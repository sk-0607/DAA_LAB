#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(vector<double>& data, int left, int right, int pivotIndex) {
    double pivot = data[pivotIndex];
    swap(data[pivotIndex], data[right]);
    int store = left;

    for (int i = left; i < right; ++i) {
        if (data[i] < pivot) {
            swap(data[i], data[store]);
            ++store;
        }
    }

    swap(data[store], data[right]);
    return store;
}

double quickSelect(vector<double>& data, int left, int right, int k) {
    if (left == right)
        return data[left];

    srand(time(0));
    int pivotIndex = left + rand() % (right - left + 1);
    pivotIndex = partition(data, left, right, pivotIndex);

    if (k == pivotIndex)
        return data[k];
    else if (k < pivotIndex)
        return quickSelect(data, left, pivotIndex - 1, k);
    else
        return quickSelect(data, pivotIndex + 1, right, k);
}

double findKthSmallest(vector<double>& data, int k) {
    return quickSelect(data, 0, data.size() - 1, k - 1);
}

int main() {
    int n, k;
    cin >> n;

    vector<double> values(n);
    for (int i = 0; i < n; ++i)
        cin >> values[i];

    cin >> k;
    if (k < 1 || k > n) {
        cout << "Invalid" << endl;
        return 1;
    }

    cout << "Output:" << endl;
    double result = findKthSmallest(values, k);
    cout << result << endl;

    return 0;
}
