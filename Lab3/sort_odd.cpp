#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& data, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);

    vector<int> merged;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (data[i] < data[j]) merged.push_back(data[i++]);
        else merged.push_back(data[j++]);
    }
    while (i <= mid) merged.push_back(data[i++]);
    while (j <= right) merged.push_back(data[j++]);

    for (int k = 0; k < merged.size(); ++k)
        data[left + k] = merged[k];
}

void sortOddIndexed(vector<int>& arr) {
    vector<int> values, indices;
    for (int i = 0; i < arr.size(); i += 2) {
        indices.push_back(i);
        values.push_back(arr[i]);
    }

    mergeSort(values, 0, values.size() - 1);

    for (int i = 0; i < indices.size(); ++i)
        arr[indices[i]] = values[i];
}

int main() {
    int size;
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; ++i)
        cin >> arr[i];

    sortOddIndexed(arr);

    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}
