#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    bool inQueue = false;
};


void printQueue(queue<int> q) {
    if (q.empty()) {
        cout << "[ Empty ]" << endl;
        return;
    }
    cout << "[ ";
    while (!q.empty()) {
        cout << "P" << q.front() + 1;
        q.pop();
        if (!q.empty()) cout << ", ";
    }
    cout << " ]" << endl;
}

int main() {
    int tq, n;
    cout << "Time Quantum: "; cin >> tq;
    cout << "Number of Processes: "; cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].id = i;
        cout << "Arrival Time, Needed Time P" << i + 1 << ": ";
        cin >> p[i].arrival_time >> p[i].burst_time;
        p[i].remaining_time = p[i].burst_time;
    }

    queue<int> q;
    int currentTime = 0;
    int completed = 0;

    cout << "\nQueue updates:" << endl;

    for (int i = 0; i < n; i++) {
        if (p[i].arrival_time <= currentTime) {
            q.push(i);
            p[i].inQueue = true;
        }
    }

    if(!q.empty()) printQueue(q);

    while (completed < n) {
        if (q.empty()) {
            currentTime++;
            for (int i = 0; i < n; i++) {
                if (p[i].arrival_time <= currentTime && !p[i].inQueue) {
                    q.push(i);
                    p[i].inQueue = true;
                }
            }
            if(!q.empty()) printQueue(q);
            continue;
        }

        int idx = q.front();
        q.pop();

        int executeTime = min(p[idx].remaining_time, tq);

        for (int i = 0; i < executeTime; i++) {
            currentTime++;
            for (int j = 0; j < n; j++) {
                if (p[j].arrival_time == currentTime && !p[j].inQueue) {
                    q.push(j);
                    p[j].inQueue = true;
                }
            }
        }

        p[idx].remaining_time -= executeTime;

        if (p[idx].remaining_time > 0) {
            q.push(idx);
        } else {
            p[idx].completion_time = currentTime;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            completed++;
        }

        printQueue(q);
    }

    cout << "\nProcess Completion Time Turnaround Time Waiting Time" << endl;
    double totalWT = 0;
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].id + 1 << " "
             << setw(12) << p[i].completion_time << " "
             << setw(15) << p[i].turnaround_time << " "
             << setw(12) << p[i].waiting_time << endl;
        totalWT += p[i].waiting_time;
    }

    cout << fixed << setprecision(3) << "Average Waiting Time: " << totalWT / n << endl;

    return 0;
}

/*

2
2
0 2
5 4
---
2
3
0 5
1 3
2 1

*/