#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cout << "Enter total number of processes: ";
    cin >> n;

    int bt[n], p[n];
    int ct[n], tat[n], wt[n];

    cout << "\nEnter Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        cout << "P" << i + 1 << ": ";
        cin >> bt[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[j] < bt[i]) {
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    ct[0] = bt[0];
    for (int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
    }

    cout << "\n---------------------------------------------------\n";
    cout << "Process\tBT\tCT\tTAT\tWT\n";
    cout << "---------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }
    cout << "---------------------------------------------------\n";

    float avgTAT = 0, avgWT = 0;
    for (int i = 0; i < n; i++) {
        avgTAT += tat[i];
        avgWT += wt[i];
    }

    avgTAT /= n;
    avgWT /= n;

    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time = " << avgTAT << " ms";
    cout << "\nAverage Waiting Time = " << avgWT << " ms\n";

    return 0;
}
