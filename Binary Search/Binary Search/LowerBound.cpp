// Program to find the lower bound for the given key using binary search
#include <bits/stdc++.h>
using namespace std;
int lower_bound(vector<int> &v, int key) {
    int lo = 0, hi = v.size() - 1;
    while(hi - lo > 1) {
        int mid = (lo + hi)/2;
        if(v[mid] < key) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    if(v[lo] >= key) return lo;
    if(v[hi] >= key) return hi;
    return -1;
}
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
    int lb = lower_bound(v, key);
    cout << lb << " " << ((lb == -1) ? -1 : v[lb]);
    return 0;
}