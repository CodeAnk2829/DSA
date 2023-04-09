// Program to perform binary search on an array (Recursively)
#include <bits/stdc++.h>
using namespace std;
void binary_search(vector<int> &v, int lo, int hi, int key) {
    if(lo > hi) {
        cout << "Not found";
        return;
    }
    int mid = (lo + hi)/2;
    if(v[mid] == key) {
        cout << "Key found at " << mid << endl;
        return;
    }
    if(v[mid] < key) {
        binary_search(v, mid + 1, hi, key);
    } else {
        binary_search(v, lo, mid, key);
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int key;
    cin >> key;
    sort(a.begin(), a.end());
    binary_search(a, 0, n - 1, key);
    return 0;
}
