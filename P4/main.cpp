#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int at, bt, remaining_bt;
    int ct, tat, wt;
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
        cin >> p[i].at >> p[i].bt;
        p[i].remaining_bt = p[i].bt;
    }

    queue<int> q;
    int currentTime = 0;
    int completed = 0;

    cout << "\nQueue updates:" << endl;

    for (int i = 0; i < n; i++) {
        if (p[i].at <= currentTime) {
            q.push(i);
            p[i].inQueue = true;
        }
    }

    if(!q.empty()) printQueue(q);

    while (completed < n) {
        if (q.empty()) {
            currentTime++;
            for (int i = 0; i < n; i++) {
                if (p[i].at <= currentTime && !p[i].inQueue) {
                    q.push(i);
                    p[i].inQueue = true;
                }
            }
            if(!q.empty()) printQueue(q);
            continue;
        }

        int idx = q.front();
        q.pop();

        int executeTime = min(p[idx].remaining_bt, tq);

        for (int i = 0; i < executeTime; i++) {
            currentTime++;
            for (int j = 0; j < n; j++) {
                if (p[j].at == currentTime && !p[j].inQueue) {
                    q.push(j);
                    p[j].inQueue = true;
                }
            }
        }

        p[idx].remaining_bt -= executeTime;

        if (p[idx].remaining_bt > 0) {
            q.push(idx);
        } else {
            p[idx].ct = currentTime;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            completed++;
        }

        printQueue(q);
    }

    cout << "\nProcess Completion Time Turnaround Time Waiting Time" << endl;
    double totalWT = 0;
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].id + 1 << " "
             << setw(12) << p[i].ct << " "
             << setw(15) << p[i].tat << " "
             << setw(12) << p[i].wt << endl;
        totalWT += p[i].wt;
    }

    cout << fixed << setprecision(3) << "Average Waiting Time: " << totalWT / n << endl;

    return 0;
}