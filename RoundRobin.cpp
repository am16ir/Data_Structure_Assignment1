#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    bool ok = false;
};

void print(queue<int> q) {
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
    int time_quantum, n;
    cin >> time_quantum >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].id = i;
        cin >> p[i].arrival_time >> p[i].burst_time;
        p[i].remaining_time = p[i].burst_time;
    }

    queue<int> q;
    int current_time = 0;
    int finished = 0;
    double total = 0;

    cout << "Queue updates:" << endl;

    while (finished < n) {

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && p[i].ok == false) {
                q.push(i);
                p[i].ok = true;
            }
        }

        if (q.empty()) {
            current_time++;
            continue;
        }

        print(q);

        int current = q.front();
        q.pop();

        int run_time;
        if (p[current].remaining_time < time_quantum)
            run_time = p[current].remaining_time;
        else
            run_time = time_quantum;

        for (int i = 0; i < run_time; i++) {
            current_time++;

            for (int j = 0; j < n; j++) {
                if (p[j].arrival_time <= current_time && p[j].ok == false) {
                    q.push(j);
                    p[j].ok = true;
                }
            }
        }

        p[current].remaining_time -= run_time;

        if (p[current].remaining_time > 0) {
            q.push(current);
        } else {
            p[current].completion_time = current_time;
            p[current].turnaround_time = p[current].completion_time - p[current].arrival_time;
            p[current].waiting_time = p[current].turnaround_time - p[current].burst_time;

            total += p[current].waiting_time;
            finished++;
        }
    }

    print(q);

    cout << "Process Completion Time Turnaround Time Waiting Time" << endl;

    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << " "
             << setw(12) << p[i].completion_time << " "
             << setw(15) << p[i].turnaround_time << " "
             << setw(12) << p[i].waiting_time << endl;
    }

    cout << fixed << setprecision(3);
    cout << "Average Waiting Time: " << total / n << endl;

    return 0;
}
