#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

vector<int> findMaxProfit(vector<int>& arr, int n) {
    vector<int> tempArr;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            tempArr.push_back(arr[i]);
            i++;
        } else {
            continue;
        }
    }
    return tempArr;
}

int main() {
    int n;
    cout << "Input: " << endl;
    cin >> n;

    vector<int> netProfit(n);
    for (int i = 0; i < n; i++) {
        cin >> netProfit[i];
    }

    vector<int> profitArr;
    profitArr = findMaxProfit(netProfit, n);

    cout << "Output: " << endl;
    for (int num : profitArr) {
        cout << num << endl;
    }

    cout << "The maximum sum is = " << accumulate(profitArr.begin(), profitArr.end(), 0);

    return 0;

}