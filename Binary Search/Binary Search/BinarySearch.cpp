// Program to perform binary search on an array
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int key;
    cin >> key;
    int lo = 0, hi = n - 1;
    while(hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if(v[mid] < key) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    if(v[lo] == key) {
        cout << "Found at " << lo << endl;
    } else if(v[hi] == key) {
        cout << "Found at " << hi << endl;
    } else {
        cout << "Not found" << endl;
    }
    return 0;
}