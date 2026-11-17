#include <bits/stdc++.h>
using namespace std;

struct Process {
int pid;
int bt;
int at;
int rt;
int ct;
int tat;
int wt;
};

int main() {
int n, tq;
cout << "Enter number of processes: ";
cin >> n;

vector<Process> proc(n);

for (int i = 0; i < n; i++) {
    proc[i].pid = i + 1;
    cout << "Enter Burst Time for P" << i + 1 << ": ";
    cin >> proc[i].bt;
    proc[i].rt = proc[i].bt;
    cout << "Enter Arrival Time for P" << i + 1 << ": ";
    cin >> proc[i].at;
}

cout << "Enter Time Quantum: ";
cin >> tq;

int time = 0;
queue<int> q;
vector<bool> inQueue(n, false);
int completed = 0;

for (int i = 0; i < n; i++) {
    if (proc[i].at <= time) {
        q.push(i);
        inQueue[i] = true;
    }
}

while (completed < n) {
    if (q.empty()) {
        int next = -1;
        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && proc[i].rt > 0) {
                next = i;
                break;
            }
        }
        if (next != -1)
            time = proc[next].at;
        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && proc[i].rt > 0 && proc[i].at <= time) {
                q.push(i);
                inQueue[i] = true;
            }
        }
    }

    if (!q.empty()) {
        int idx = q.front();
        q.pop();

        int exec = min(tq, proc[idx].rt);
        proc[idx].rt -= exec;
        time += exec;
        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && proc[i].rt > 0 && proc[i].at <= time) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (proc[idx].rt > 0) {
            q.push(idx);
        } else {
            proc[idx].ct = time;
            proc[idx].tat = proc[idx].ct - proc[idx].at;
            proc[idx].wt = proc[idx].tat - proc[idx].bt;
            completed++;
        }
    }
}

cout << "\nFinal Table:\n";
cout << "PID\tBT\tAT\tCT\tTAT\tWT\n";
for (int i = 0; i < n; i++) {
    cout << "P" << proc[i].pid << "\t"
         << proc[i].bt << "\t"
         << proc[i].at << "\t"
         << proc[i].ct << "\t"
         << proc[i].tat << "\t"
         << proc[i].wt << "\n";
}

return 0;
}
