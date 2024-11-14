#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

// DFA structure
struct DFA {
    int numStates;
    int startState;
    set<int> acceptingStates;
    map<int, map<char, int>> transitions;
};

// Function to minimize DFA
DFA minimizeDFA(const DFA& dfa) {
    vector<set<int>> partitions = {dfa.acceptingStates}; // Accepting states partition
    set<int> nonAcceptingStates;

    for (int i = 0; i < dfa.numStates; i++) {
        if (dfa.acceptingStates.find(i) == dfa.acceptingStates.end()) {
            nonAcceptingStates.insert(i); // Add non-accepting states
        }
    }
    if (!nonAcceptingStates.empty()) {
        partitions.push_back(nonAcceptingStates); // Non-accepting states partition
    }

    // Refining partitions
    bool refined;
    do {
        refined = false;
        vector<set<int>> newPartitions;

        for (const auto& group : partitions) {
            map<int, set<int>> splitGroups;

            // Partition based on transition states
            for (int state : group) {
                int key = 0;
                for (char symbol = 'a'; symbol <= 'z'; symbol++) { // Assuming 'a' to 'z' as input alphabet
                    if (dfa.transitions.count(state) && dfa.transitions.at(state).count(symbol)) {
                        int toState = dfa.transitions.at(state).at(symbol);

                        // Find partition index of toState
                        for (int i = 0; i < partitions.size(); i++) {
                            if (partitions[i].find(toState) != partitions[i].end()) {
                                key = key * 31 + static_cast<int>(i); // Unique key per transition
                                break;
                            }
                        }
                    } else {
                        key = key * 31 + -1; // No transition for symbol
                    }
                }
                splitGroups[key].insert(state);
            }

            if (splitGroups.size() > 1) refined = true;
            for (const auto& split : splitGroups) {
                newPartitions.push_back(split.second);
            }
        }

        partitions = newPartitions;
    } while (refined);

    // Map original states to new states
    map<int, int> stateMap;
    for (size_t i = 0; i < partitions.size(); i++) {
        for (int state : partitions[i]) {
            stateMap[state] = i;
        }
    }

    // Build minimized DFA
    DFA minimizedDFA;
    minimizedDFA.numStates = partitions.size();
    minimizedDFA.startState = stateMap[dfa.startState];
    for (int state : dfa.acceptingStates) {
        minimizedDFA.acceptingStates.insert(stateMap[state]);
    }
    for (auto it = dfa.transitions.begin(); it != dfa.transitions.end(); ++it) {
        int state = it->first;
        const auto& transitionMap = it->second;
        for (auto jt = transitionMap.begin(); jt != transitionMap.end(); ++jt) {
            char symbol = jt->first;
            int toState = jt->second;
            minimizedDFA.transitions[stateMap[state]][symbol] = stateMap[toState];
        }
    }

    return minimizedDFA;
}

// Helper function to print DFA
void printDFA(const DFA& dfa) {
    cout << "Number of states: " << dfa.numStates << endl;
    cout << "Start state: " << dfa.startState << endl;
    cout << "Accepting states: ";
    for (int state : dfa.acceptingStates) {
        cout << state << " ";
    }
    cout << "\nTransitions:\n";
    for (auto it = dfa.transitions.begin(); it != dfa.transitions.end(); ++it) {
        int state = it->first;
        const auto& transitionMap = it->second;
        for (auto jt = transitionMap.begin(); jt != transitionMap.end(); ++jt) {
            char symbol = jt->first;
            int toState = jt->second;
            cout << "State " << state << " --" << symbol << "--> " << toState << endl;
        }
    }
}

int main() {
    DFA dfa;
    dfa.numStates = 5;
    dfa.startState = 0;
    dfa.acceptingStates = {2, 4};

    dfa.transitions = {
        {0, {{'a', 1}, {'b', 3}}},
        {1, {{'a', 2}, {'b', 4}}},
        {2, {{'a', 2}, {'b', 4}}},
        {3, {{'a', 1}, {'b', 3}}},
        {4, {{'a', 2}, {'b', 4}}}
    };

    cout << "Original DFA:\n";
    printDFA(dfa);

    DFA minimizedDFA = minimizeDFA(dfa);

    cout << "\nMinimized DFA:\n";
    printDFA(minimizedDFA);

    return 0;
}