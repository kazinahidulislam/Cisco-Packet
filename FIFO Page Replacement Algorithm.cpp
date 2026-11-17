#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, f, pageFault = 0;
    cout << "Enter total number of pages: ";
    cin >> n;
    int page[n];
    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++)
        cin >> page[i];
    cout << "Enter number of frames: ";
    cin >> f;
    queue<int> frame;
    int present[100] = {0};
    for (int i = 0; i < n; i++) {
        int curr = page[i];
        if (present[curr] == 0) {
            if (frame.size() == f) {
                int removePage = frame.front();
                frame.pop();
                present[removePage] = 0;
            }
            frame.push(curr);
            present[curr] = 1;
            pageFault++;
        }
    }
    cout << "\nTotal Page Faults = " << pageFault << endl;
    return 0;
}
