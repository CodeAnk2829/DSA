#include <bits/stdc++.h>
using namespace std;
int knapSnack(int* val, int* wt, int n, int w) {
    if(w == 0 || n <= 0) {
        return 0;
    }
    int a = INT_MIN;
    if(wt[n - 1] <= w) {
        a = val[n - 1] + knapSnack(val, wt, n - 1, w - wt[n - 1]);
    }
    int b = knapSnack(val, wt, n - 1, w);
    int ans = max(a, b);
    return ans;
}

int main() {
    int n, w;
    cin >> n >> w;
    int val[n];
    int wt[n];
    for(int i = 0; i < n; ++i) cin >> val[i];
    for(int i = 0; i < n; ++i) cin >> wt[i];
    cout << knapSnack(val, wt, n, w);
    return 0;
}
