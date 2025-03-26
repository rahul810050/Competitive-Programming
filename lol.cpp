#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int id, arrival, burst, remaining, completion, turnaround, waiting;
};

void RoundRobin(Process proc[], int n, int quantum) {
    queue<int> q;
    int currentTime = 0, completed = 0;
    bool inQueue[n] = {false};

    for (int i = 0; i < n; i++) 
        proc[i].remaining = proc[i].burst;

    int i = 0;
    while (completed < n) {
        for (; i < n && proc[i].arrival <= currentTime; i++) {
            if (!inQueue[i]) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (q.empty()) {
            currentTime++;
            continue;
        }

        int index = q.front();
        q.pop();
        inQueue[index] = false;

        int execTime = min(quantum, proc[index].remaining);
        proc[index].remaining -= execTime;
        currentTime += execTime;

        if (proc[index].remaining == 0) {
            proc[index].completion = currentTime;
            proc[index].turnaround = proc[index].completion - proc[index].arrival;
            proc[index].waiting = proc[index].turnaround - proc[index].burst;
            completed++;
        } else {
            q.push(index);
            inQueue[index] = true;
        }
    }

    cout << "\nID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << proc[i].id << "\t" << proc[i].arrival << "\t" << proc[i].burst << "\t" 
             << proc[i].completion << "\t" << proc[i].turnaround << "\t" << proc[i].waiting << "\n";
    }
}

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    Process proc[n];
    for (int i = 0; i < n; i++) {
			cout << "Enter Arrival Time and Burst Time for each process: "<<i+1<<": ";
        proc[i].id = i + 1;
        cin >> proc[i].arrival >> proc[i].burst;
    }

    cout << "Enter time quantum: ";
    cin >> quantum;

    RoundRobin(proc, n, quantum);
    return 0;
}