#include<bits/stdc++.h>

using namespace std;

struct Process
{
    int arrival_time;
    int burst_time;
    int Turnaround_time;
    int waiting_time;
    int process_id;
    int remaining_time;
};

bool compareAT_BT(Process a, Process b)
{
    return a.arrival_time < b.arrival_time;
}

int main ()
{
    cout <<"enter process number :" << endl;
    int num;
    cin >> num;

    Process process[num];

    for (int i = 0; i < num; i++)
    {
        cout << "process" << i+1 << " arrival & burst time: ";
        cin >> process[i].arrival_time >> process[i].burst_time;

        process[i].process_id = i + 1;
        process[i].remaining_time = process[i].burst_time;
    }

    int quantum;
    cout << "Enter time quantum: ";
    cin >> quantum;

    sort(process, process + num, compareAT_BT);

    cout << setw(15) << "process"
         << setw(15) << "arrival"
         << setw(15) << "burst time" << endl;

    for (int i = 0; i < num; i++)
    {
        cout << setw(15) << process[i].process_id
             << setw(15) << process[i].arrival_time
             << setw(15) << process[i].burst_time << endl;
    }

    int time = 0;
    queue<int> q;
    bool visited[num] = {false};
    int completed_process = 0;

    for (int i = 0; i < num; i++)
    {
        if (process[i].arrival_time <= time && !visited[i])
        {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty())
    {
        int idx = q.front();
        q.pop();

        if (process[idx].remaining_time > quantum)
        {
            time += quantum;
            process[idx].remaining_time -= quantum;
        }
        else
        {
            time += process[idx].remaining_time;
            process[idx].remaining_time = 0;
            completed_process++;

            process[idx].Turnaround_time = time - process[idx].arrival_time;
            process[idx].waiting_time = process[idx].Turnaround_time - process[idx].burst_time;
        }

        for (int i = 0; i < num; i++)
        {
            if (process[i].arrival_time <= time && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }

        if (process[idx].remaining_time > 0)
        {
            q.push(idx);
        }

        if (q.empty())
        {
            for (int i = 0; i < num; i++)
            {
                if (!visited[i])
                {
                    time = process[i].arrival_time;
                    q.push(i);
                    visited[i] = true;
                    break;
                }
            }
        }
    }

    cout << "\nFinal Results:\n";
    cout << setw(15) << "Process"
         << setw(15) << "Arrival"
         << setw(15) << "Burst"
         << setw(15) << "Waiting"
         << setw(15) << "Turnaround" << endl;

    for (int i = 0; i < num; i++)
    {
        cout << setw(15) << process[i].process_id
             << setw(15) << process[i].arrival_time
             << setw(15) << process[i].burst_time
             << setw(15) << process[i].waiting_time
             << setw(15) << process[i].Turnaround_time << endl;
    }
}
































































































































































































/*#include<iostream>

using namespace std;

struct Process
{
    int arrival_time;
    int burst_time;
    int Turnaround_time;
    int waiting_time;
    int process_id;
};

bool compareAT_BT()

int main ()
{
    cout <<"enter process number :" << endl;
    int num;
    cin>> num;

    process process [num];

    for (int i=0; i<num;i++)
    {
        cout << "process"<<i+1<<"arrival & burst time: ";
        cin>> process[i].arrival_time>>process[i].brust_time;

        process[i]process_id=i+1;
    }

    int completed_process = 0;

    bool completed(num);
    for (int i= 0; i<num; i++)
    {
        completed[i]= false;
    }

    sort(process.process+num);

    cout<<setw(15) << "process"
            <<setw(15)<<"arrival";
            <<setw(15)<<"burst time"<<endl;

    for (int i = 0; i<num; i++)
    {
        cout << setw(15)<<process[i].process_id
                 << setw(15)<<process[i].arrival_time
                 << setw(15)<<process[i].burst_time<<endl;
    }

    while (completed_process<=num)
    {
        int idx = -1;
        int time = 0;
        int min burst = INT MAX;

        for (int i = 0; i<num; i++)
        {
            if (completed[i] && process[i].arrival_time <=time)
            {
                min_brust = process[i].brust_time;
            }
        }

    }

}

*/
