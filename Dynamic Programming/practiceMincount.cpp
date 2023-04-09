#include <bits/stdc++.h>
using namespace std;

int getMinCountHelper(int n, vector<int>& dp) {
    if(n == 0) {
        return 0;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    int minCount = INT_MAX;

    for(int i = 1; i * i <= n; ++i) {
        minCount = min(minCount, 1 + getMinCountHelper(n - (i * i), dp));
    }
    return dp[n] = minCount;
}

int getMinCount(int n) {
    vector<int> dp(n + 1, -1);
    return getMinCountHelper(n, dp);
}

int main() {
    int n;
    cin >> n;
    cout << getMinCount(n) << endl;
    return 0;
}