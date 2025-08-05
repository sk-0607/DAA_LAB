#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int mergeAndCount(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    int invCount = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            invCount += (left.size() - i);
        }
    }

    while (i < left.size())
        arr[k++] = left[i++];

    while (j < right.size())
        arr[k++] = right[j++];

    return invCount;
}

int countInversions(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int m = (l + r) / 2;
    int inv = 0;
    inv += countInversions(arr, l, m);
    inv += countInversions(arr, m + 1, r);
    inv += mergeAndCount(arr, l, m, r);
    return inv;
}

int main() {
    int n;
    cin >> n;
    cout << "Input:" << endl;
    vector<int> prelim(n), final(n);
    for (int i = 0; i < n; ++i) cin >> prelim[i];
    for (int i = 0; i < n; ++i) cin >> final[i];

    unordered_map<int, int> rankIndex;
    for (int i = 0; i < n; ++i)
        rankIndex[prelim[i]] = i + 1;

    vector<int> mapped(n);
    for (int i = 0; i < n; ++i)
        mapped[i] = rankIndex[final[i]];

    cout << "Output:" << endl;
    cout << countInversions(mapped, 0, n - 1) << endl;
    return 0;
}

