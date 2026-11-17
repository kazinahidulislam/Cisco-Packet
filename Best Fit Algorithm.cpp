#include <bits/stdc++.h>
using namespace std;

int main() {
    int process[4] = {100, 250, 180, 300};
    int block[5] = {200, 400, 350, 500, 250};
    int allocation[4];

    for(int i=0;i<4;i++) allocation[i]=-1;

    for(int i=0;i<4;i++){
        int min_block = INT_MAX;
        int index = -1;
        for(int j=0;j<5;j++){
            if(block[j]>=process[i] && block[j]<min_block){
                min_block = block[j];
                index = j;
            }
        }
        if(index!=-1){
            allocation[i] = index;
            block[index] -= process[i];
        }
    }

    cout << setw(15) << "Process" << setw(15) << "Size" << setw(15) << "Location" << endl;
    for(int i=0;i<4;i++){
        cout << setw(15) << i+1 << setw(15) << process[i] << setw(15) << allocation[i] << endl;
    }
}
