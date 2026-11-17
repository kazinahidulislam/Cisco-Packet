#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    bool done;
};

int main() {
    int n;
    cout << "Enter total number of processes: ";
    cin >> n;

    Process p[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for Process P" << i + 1 << ": ";
        p[i].pid = i + 1;
        cin >> p[i].at >> p[i].bt;
        p[i].done = false;
    }

    int completed = 0, current_time = 0;
    float total_tat = 0, total_wt = 0;

    while (completed < n) {
        int idx = -1;
        int min_bt = 1e9;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= current_time && !p[i].done) {
                if (p[i].bt < min_bt) {
                    min_bt = p[i].bt;
                    idx = i;
                }
                else if (p[i].bt == min_bt && p[i].at < p[idx].at) {
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            current_time += p[idx].bt;
            p[idx].ct = current_time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            total_tat += p[idx].tat;
            total_wt += p[idx].wt;
            p[idx].done = true;
            completed++;
        } else {
            current_time++;
        }
    }

    cout << "\n--------------------------------------------------------------\n";
    cout << "Process\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << "\n";
    }

    cout << "--------------------------------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Average Turnaround Time = " << total_tat / n << " ms\n";
    cout << "Average Waiting Time = " << total_wt / n << " ms\n";

    return 0;
}

