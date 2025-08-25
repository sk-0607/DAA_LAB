#include <bits/stdc++.h>
using namespace std;

int rodCutRecursive(const vector<int>& price, int n) {
    if (n == 0) return 0;
    int maxVal = INT_MIN;
    for (int i = 1; i <= n; i++)
        maxVal = max(maxVal, price[i - 1] + rodCutRecursive(price, n - i));
    return maxVal;
}

int rodCutMemoizedUtil(const vector<int>& price, int n, vector<int>& dp) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    int maxVal = INT_MIN;
    for (int i = 1; i <= n; i++)
        maxVal = max(maxVal, price[i - 1] + rodCutMemoizedUtil(price, n - i, dp));
    return dp[n] = maxVal;
}

int rodCutBottomUp(const vector<int>& price, int n, vector<int>& cuts) {
    vector<int> dp(n + 1, 0);
    cuts.assign(n + 1, 0);
    for (int len = 1; len <= n; len++) {
        int maxVal = INT_MIN;
        for (int cut = 1; cut <= len; cut++) {
            if (price[cut - 1] + dp[len - cut] > maxVal) {
                maxVal = price[cut - 1] + dp[len - cut];
                cuts[len] = cut;
            }
        }
        dp[len] = maxVal;
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Input:" << endl;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    int rodLen;
    cin >> rodLen;
    cout << "Output:" << endl;
    cout << rodCutRecursive(price, rodLen) << endl;

    vector<int> dpMemo(rodLen + 1, -1);
    cout << rodCutMemoizedUtil(price, rodLen, dpMemo) << endl;

    vector<int> cuts;
    cout << rodCutBottomUp(price, rodLen, cuts) << endl;
    int len = rodLen;
    while (len > 0) {
        cout << cuts[len] << endl;
        len -= cuts[len];
    }
    return 0;
}
