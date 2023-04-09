#include <bits/stdc++.h>
using namespace std;
int knapSack(int* val, int* wt, int n, int w) {
    int** dp = new int*[n + 1];
    for(int i = 0; i <= n; ++i) {
        dp[i] = new int[w + 1];
    }
    for(int i = n; i > 0 && w != 0; ++i) {
        
    }
}
int main() {
    int n, w;
    cin >> n >> w;
    int val[n];
    int wt[n];
    for(int i = 0; i < n; ++i) cin >> val[i];
    for(int i = 0; i < n; ++i) cin >> wt[i];
    cout << knapSack(val, wt, n, w);
    return 0;
}
