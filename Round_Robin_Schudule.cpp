#include <bits/stdc++.h>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    
    Process(int idd ,int arr , int burst){
        id = idd;
        arrival_time = arr;
        burst_time = burst;
        remaining_time = burst;
        completion_time = 0;
        turnaround_time = 0;
        waiting_time = 0;
    }

};

int main() {
    int quantum_time = 0 , number_of_processes;
    cout<<"Enter Time Quantum: \n";
    cin>>quantum_time;
    cout<<"Enter Number Of Processes: \n"; 
    cin>>number_of_processes;

    vector<Process>processes;
    
    for (int i = 0;i < number_of_processes; i++){
        int arr , burs;
        cout<<"P"<<i<<" arrival time , needed time: \n";
        cin>>arr>>burs;
        Process p(i,arr,burs);
        processes.push_back(p);
    }
    
    queue<int>Readyqueue;
    
    int cur_time = 0 , used_quantum , current_process = -1 , number_finished_processes = 0;

    for (auto x : processes){
        if (x.arrival_time == cur_time)
            Readyqueue.push(x.id);
    }

    while (true){
        
        // cpu is idle no running process and no waiting process in the q
        if (current_process == -1 && Readyqueue.empty()){
            cur_time++;
            for (auto x : processes){
                if (x.arrival_time == cur_time)
                    Readyqueue.push(x.id);
            }
            continue;
        }
        // 
        else if (current_process == -1 && !Readyqueue.empty()){
            current_process = Readyqueue.front();
            Readyqueue.pop();
            used_quantum = 0;
        }
        //cout << "Time " << cur_time << " running P" << current_process << "\n";
        // move 1 unit time
        processes[current_process].remaining_time--;
        used_quantum++;
        cur_time++;

        // calc el w8ing time
        for (auto& x : processes){
            if (x.id == processes[current_process].id)continue;
            if (x.arrival_time < cur_time && x.remaining_time > 0)
                x.waiting_time++;
        } 
        // check new processes
        for (auto x : processes){
            if (x.arrival_time == cur_time)
                Readyqueue.push(x.id);
        }


        // process finished
        if (processes[current_process].remaining_time == 0){
            processes[current_process].completion_time = cur_time;
            number_finished_processes++;
            current_process = -1; 
        }
        // quantum finished  but process yet
        else if (used_quantum == quantum_time){
            Readyqueue.push(processes[current_process].id);
            current_process = -1;
        }

        // breaking cond
        
        if (number_finished_processes == number_of_processes)break;
    }

    int total_wait = 0;
    for (auto& x : processes){
        x.turnaround_time = x.waiting_time + x.burst_time;
        total_wait+=x.waiting_time;
    }
    for (auto x : processes){
        cout<<"Process"<<x.id<<" ";
        cout<<"Completion Time: "<<x.completion_time<<" Turn Arround Time: "<<x.turnaround_time;
        cout<<" Waiting Time: "<<x.waiting_time<<"\n";
    }
    float avg_waiting = (float)total_wait / number_of_processes;
    cout<<"Average Waiting Time: "<<avg_waiting;

    return 0;
}