#include <bits/stdc++.h>
using namespace std;
int pageFaults(vector<int>& pages, int n, int capacity) {
    unordered_set<int> s;
    unordered_map<int, int> idx;
    int pageFaults = 0;
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        if (s.find(page) == s.end()) {
            pageFaults++;
            if (s.size() == capacity) {
                int lruPage = -1, leastIndex = INT_MAX;
                for (auto it : s) {
                    if (idx[it] < leastIndex) {
                        leastIndex = idx[it];
                        lruPage = it;
                    }
                }
                s.erase(lruPage);
            }
            s.insert(page);
        }
        idx[page] = i;
        cout << "Step " << i + 1 << " -> Frames: ";
        for (int p : s) cout << p << " ";
        cout << endl;
    }
    return pageFaults;
}
int main() {
    int n, capacity;
    cout << "Enter total number of pages: ";
    cin >> n;
    vector<int> pages(n);
    cout << "Enter page sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    cout << "Enter number of frames: ";
    cin >> capacity;
    int faults = pageFaults(pages, n, capacity);
    cout << "\nTotal Page Faults: " << faults << endl;
    return 0;
}
