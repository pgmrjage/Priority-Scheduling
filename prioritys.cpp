#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <queue>
#include <iomanip>
using namespace std;

// Structure for storing Process details
struct Process {
    int arrival_time;
    int burst_time;
    int priority;  // User-defined priority
    string process_name;

    // Comparator for priority_queue to prioritize lower numbers as higher priority
    bool operator>(const Process& other) const {
        return priority > other.priority;  // Lower priority number is higher priority
    }
};

int priority(int processes) {
    int at[processes], bt[processes], wt[processes];
    string processName[processes];
    int priority[processes];  // Priority array

    cout << "Input ARRIVAL TIME, BURST TIME, and PRIORITY for each process:\n";
    for (int i = 0; i < processes; i++) {
        processName[i] = "P" + to_string(i + 1);
        cout << "Process [" << i + 1 << "]\n";
        cout << "Arrival Time: "; cin >> at[i];
        cout << "Burst Time: "; cin >> bt[i];
        cout << "Priority: "; cin >> priority[i];
    }

    // Priority queue to sort processes based on priority
    priority_queue<Process, vector<Process>, greater<Process>> pq;
    for (int i = 0; i < processes; i++) {
        pq.push(Process{at[i], bt[i], priority[i], processName[i]});
    }

    // Simulate FCFS with Priority
    float wtTotal = 0;
    int currentTime = 0;

    // Output Section
    cout << "Process\tArrival Time\tBurst Time\tPriority\tWaiting Time\n";
    while (!pq.empty()) {
        Process p = pq.top(); pq.pop();
        
        int waitTime = max(0, currentTime - p.arrival_time);
        wt[currentTime] += waitTime;
        wtTotal += waitTime;

        currentTime += p.burst_time;

        cout << p.process_name << "\t" << p.arrival_time << "\t\t" << p.burst_time
             << "\t\t" << p.priority << "\t\t" << waitTime <<endl;
    }

    cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << wtTotal / processes << endl;
    return 0;
}

int main() {
    int mode;
    char again = 'Y';

    do {
        cout << "=====================================" << endl;
        cout << "PRIORITY QUEUE SCHEDULING" << endl;
        cout << "=====================================" << endl;
        int processes;
        cout << "Input number of processes: "; cin >> processes;
            priority(processes);
        cout << "Invalid choice. Try again? (Y/N): "; cin >> again;

    } while (again == 'Y' || again == 'y');
    system("pause");
    return 0;
}
