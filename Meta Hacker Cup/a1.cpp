// #include<bits/stdc++.h>
// using namespace std;
// #define pb push_back

// #define MAX_N 10000000

// vector<bool> sie(MAX_N + 1, true);
// vector<int> prime;

// void allPrimes(int N) {
//     sie[0] = sie[1] = false;
//     for (int i = 2; i <= N; i++) {
//         if (sie[i]) {
//             prime.pb(i);
//             for (int j = i * 2; j <= N; j += i) {
//                 sie[j] = false;
//             }
//         }
//     }
// }

// int countSubstract(int N) {
//     int count = 0;

//     vector<int> primeUptoN;
//     for (int p : prime) {
//         if (p > N) break;
//         primeUptoN.pb(p);
//     }

//     unordered_set<int> unique;

//     for (int i = 1; i < primeUptoN.size(); i++) {
//         for (int j = 0; j < i; j++) {
//             int diff = primeUptoN[i] - primeUptoN[j];
//             if (diff > N) break; 
//             if (sie[diff]) {
//                 unique.insert(diff);
//             }
//         }
//     }

//     return unique.size();
// }

// void solve() {
//     int n;
//     cin >> n;

//     int ans = countSubstract(n);
//     cout << ans << endl; 
// }

// void main_() {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

//     int t;
//     cin >> t;

//     allPrimes(MAX_N); 

//     for (int i = 1; i <= t; i++) {
//         cout << "Case #" << i << ": ";
//         solve();
//     }
// }

// static void run_with_stack_size(void (*func)(void), size_t stsize) {
//     char *stack, *send;
//     stack = (char *)malloc(stsize);
//     send = stack + stsize - 16;
//     send = (char *)((uintptr_t)send / 16 * 16);
//     asm volatile(
//         "mov %%esp, (%0)\n"
//         "mov %0, %%esp\n"
//         :
//         : "r"(send));
//     func();
//     asm volatile("mov (%0), %%esp\n" : : "r"(send));
//     free(stack);
// }

// int main() {
//     run_with_stack_size(main_, 1024 * 1024 * 1024); // Run with a 1 GiB stack
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// struct Process {
//     int id, arrivalTime, burstTime, waitingTime, turnaroundTime;
// };

// void calculateTimes(vector<Process>& processes) {
//     int n = processes.size();
//     int completionTime = 0;

//     for (int i = 0; i < n; i++) {
//         if (completionTime < processes[i].arrivalTime)
//             completionTime = processes[i].arrivalTime;

//         processes[i].waitingTime = completionTime - processes[i].arrivalTime;
//         processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
//         completionTime += processes[i].burstTime;
//     }
// }

// void printTable(const vector<Process>& processes) {
//     cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
//     for (const auto& p : processes) {
//         cout << p.id << "\t" << p.arrivalTime << "\t\t" << p.burstTime << "\t\t"
//             << p.waitingTime << "\t\t" << p.turnaroundTime << endl;
//     }
// }

// int main() {
//     int n;
//     cout << "Enter the number of processes: ";
//     cin >> n;

//     vector<Process> processes(n);

//     cout << "Enter Arrival Time and Burst Time for each process:\n";
//     for (int i = 0; i < n; i++) {
//         processes[i].id = i + 1;
//         cout << "Process " << i + 1 << " Arrival Time: ";
//         cin >> processes[i].arrivalTime;
//         cout << "Process " << i + 1 << " Burst Time: ";
//         cin >> processes[i].burstTime;
//     }

//     sort(processes.begin(), processes.end(), [](Process a, Process b) {
//         return a.arrivalTime < b.arrivalTime;
//     });

//     calculateTimes(processes);
//     printTable(processes);

//     return 0;
// }



#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Process {
    int id, arrivalTime, burstTime, completionTime, waitingTime, turnaroundTime;
};

bool sortByArrival(const Process& a, const Process& b) {
    if (a.arrivalTime == b.arrivalTime)
        return a.burstTime < b.burstTime;
    return a.arrivalTime < b.arrivalTime;
}

void computeSJF(vector<Process>& processes) {
    int n = processes.size();
    int currentTime = 0, completed = 0;
    vector<bool> isDone(n, false);

    while (completed < n) {
        int shortest = -1, minBurst = numeric_limits<int>::max();

        for (int i = 0; i < n; i++) {
            if (!isDone[i] && processes[i].arrivalTime <= currentTime && processes[i].burstTime < minBurst) {
                minBurst = processes[i].burstTime;
                shortest = i;
            }
        }

        if (shortest == -1) {
            currentTime++;
        } else {
            currentTime += processes[shortest].burstTime;
            processes[shortest].completionTime = currentTime;
            processes[shortest].turnaroundTime = currentTime - processes[shortest].arrivalTime;
            processes[shortest].waitingTime = processes[shortest].turnaroundTime - processes[shortest].burstTime;
            isDone[shortest] = true;
            completed++;
        }
    }
}

void displayResults(const vector<Process>& processes) {
    cout << "\nID  Arrival  Burst  Completion  Turnaround  Waiting\n";
    for (const auto& p : processes) {
        cout << p.id << "   " << p.arrivalTime << "       " << p.burstTime << "        "
            << p.completionTime << "          " << p.turnaroundTime << "         " << p.waitingTime << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    
    cout << "Enter Arrival Time and Burst Time for all processes in one line:\n";
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
    }

    sort(processes.begin(), processes.end(), sortByArrival);
    computeSJF(processes);
    displayResults(processes);

    return 0;
}