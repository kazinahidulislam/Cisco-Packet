#include <iostream>
using namespace std;
int main() {
    int totalProcess, totalResources;
    cout << "Enter number of processes: ";
    cin >> totalProcess;
    cout << "Enter number of resources: ";
    cin >> totalResources;
    int maxRes[10][10], alloc[10][10], need[10][10], avail[10];
    cout << "Enter Max matrix:\n";
    for (int i = 0; i < totalProcess; i++)
        for (int j = 0; j < totalResources; j++)
            cin >> maxRes[i][j];
    cout << "Enter Allocation matrix:\n";
    for (int i = 0; i < totalProcess; i++)
        for (int j = 0; j < totalResources; j++)
            cin >> alloc[i][j];
    cout << "Enter Available resources:\n";
    for (int j = 0; j < totalResources; j++)
        cin >> avail[j];
    cout << "\nCalculating Need matrix:\n";
    for (int i = 0; i < totalProcess; i++) {
        for (int j = 0; j < totalResources; j++) {
            need[i][j] = maxRes[i][j] - alloc[i][j];
            cout << need[i][j] << " ";
        }
        cout << endl;
    }
    int finish[10] = {0}, safeSeq[10], count = 0;
    while (count < totalProcess) {
        bool found = false;
        for (int p = 0; p < totalProcess; p++) {
            if (finish[p] == 0) {
                bool canRun = true;
                for (int r = 0; r < totalResources; r++) {
                    if (need[p][r] > avail[r]) {
                        canRun = false;
                        break;
                    }
                }
                if (canRun) {
                    for (int r = 0; r < totalResources; r++)
                        avail[r] += alloc[p][r];
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "\nSystem is in UNSAFE state.\n";
            return 0;
        }
    }
    cout << "\nSystem is in SAFE state.\nSafe Sequence: ";
    for (int i = 0; i < totalProcess; i++) {
        cout << "P" << safeSeq[i];
        if (i != totalProcess - 1) cout << " -> ";
    }
    cout << endl;
}

