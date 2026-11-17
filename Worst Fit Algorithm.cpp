#include <bits/stdc++.h>
using namespace std;
int main() {
    int s, b;
    cout << "Enter number of processes: ";
    cin >> s;
    cout << "Enter number of memory blocks: ";
    cin >> b;
    int process[s], block[b], allocation[s];
    for(int i=0;i<s;i++){
        cout << "Process " << i+1 << " size: ";
        cin >> process[i];
        allocation[i] = -1;
    }
    for(int j=0;j<b;j++){
        cout << "Block " << j+1 << " size: ";
        cin >> block[j];
    }
    for(int i=0;i<s;i++){
        int max_block=-1, index=-1;
        for(int j=0;j<b;j++){
            if(block[j]>=process[i] && block[j]>max_block){
                max_block=block[j];
                index=j;
            }
        }
        if(index!=-1){
            allocation[i] = index;
            block[index]-=process[i];
        }
    }
    cout << setw(15) << "Process" << setw(15) << "Size" << setw(15) << "Allocated Block" << endl;
    for(int i=0;i<s;i++){
        cout << setw(15) << i+1 << setw(15) << process[i]
             << setw(15) << (allocation[i]!=-1 ? allocation[i]+1 : -1) << endl;
    }
    return 0;
}
