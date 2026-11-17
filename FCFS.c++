#include <bits/stdc++.h>
using namespace std;

struct Process
{
    string name;
    int AT, BT, CT, TAT, WT;
};

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];
    cout << "\nEnter Process Name, Arrival Time (AT), and Burst Time (BT):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << ": ";
        cin >> p[i].name >> p[i].AT >> p[i].BT;
    }

    // Sort by Arrival Time
    sort(p, p + n, [](Process a, Process b)
    {
        return a.AT < b.AT;
    });

    int currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentTime < p[i].AT)
            currentTime = p[i].AT; // CPU idle time handling
        p[i].CT = currentTime + p[i].BT;
        currentTime = p[i].CT;
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
    }

    // Print the result table
    cout << "\n\n---------------------------------------------------------------\n";
    cout << left << setw(10) << "Process"
         << setw(10) << "AT"
         << setw(10) << "BT"
         << setw(10) << "CT"
         << setw(10) << "TAT"
         << setw(10) << "WT" << endl;
    cout << "---------------------------------------------------------------\n";

    double totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(10) << p[i].name
             << setw(10) << p[i].AT
             << setw(10) << p[i].BT
             << setw(10) << p[i].CT
             << setw(10) << p[i].TAT
             << setw(10) << p[i].WT << endl;
        totalTAT += p[i].TAT;
        totalWT += p[i].WT;
    }

    cout << "---------------------------------------------------------------\n";
    cout << "Average Turnaround Time = " << totalTAT / n << endl;
    cout << "Average Waiting Time    = " << totalWT / n << endl;

    return 0;
}
