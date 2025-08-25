#include <bits/stdc++.h>
using namespace std;

int rodCutRecursiveCost(const vector<int>& price, int n, int cost) {
    if (n == 0) return 0;
    int maxVal = price[n - 1];
    for (int i = 1; i < n; i++)
        maxVal = max(maxVal, price[i - 1] + rodCutRecursiveCost(price, n - i, cost) - cost);
    return maxVal;
}

int rodCutMemoizedCostUtil(const vector<int>& price, int n, int cost, vector<int>& dp) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    int maxVal = price[n - 1];
    for (int i = 1; i < n; i++)
        maxVal = max(maxVal, price[i - 1] + rodCutMemoizedCostUtil(price, n - i, cost, dp) - cost);
    return dp[n] = maxVal;
}

int rodCutBottomUpCost(const vector<int>& price, int n, int cost, vector<int>& cuts) {
    vector<int> dp(n + 1, 0);
    cuts.assign(n + 1, 0);
    for (int len = 1; len <= n; len++) {
        int maxVal = price[len - 1];
        int bestCut = len;
        for (int cut = 1; cut < len; cut++) {
            int val = price[cut - 1] + dp[len - cut] - cost;
            if (val > maxVal) {
                maxVal = val;
                bestCut = cut;
            }
        }
        dp[len] = maxVal;
        cuts[len] = bestCut;
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Input:" << endl;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    int rodLen, cost;
    cin >> rodLen >> cost;
    cout << "Output:" << endl;
    cout << rodCutRecursiveCost(price, rodLen, cost) << endl;

    vector<int> dpMemo(rodLen + 1, -1);
    cout << rodCutMemoizedCostUtil(price, rodLen, cost, dpMemo) << endl;

    vector<int> cuts;
    cout << rodCutBottomUpCost(price, rodLen, cost, cuts) << endl;
    int len = rodLen;
    while (len > 0) {
        cout << cuts[len] << endl;
        len -= cuts[len];
    }
    return 0;
}
