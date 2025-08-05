#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int> getFibonacciPositions(int limit) {
    vector<int> fib = {1, 2};
    while (true) {
        int next = fib[fib.size() - 1] + fib[fib.size() - 2];
        if (next > limit) break;
        fib.push_back(next);
    }
    return fib;
}

void mergeSortDesc(vector<int>& data, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSortDesc(data, left, mid);
    mergeSortDesc(data, mid + 1, right);

    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (data[i] > data[j]) temp.push_back(data[i++]);
        else temp.push_back(data[j++]);
    }
    while (i <= mid) temp.push_back(data[i++]);
    while (j <= right) temp.push_back(data[j++]);

    for (int k = 0; k < temp.size(); ++k)
        data[left + k] = temp[k];
}

void fibonacciSort(vector<int>& input) {
    int size = input.size();
    vector<int> fibPos = getFibonacciPositions(size);
    vector<int> selected;

    for (int pos : fibPos)
        selected.push_back(input[pos - 1]);

    mergeSortDesc(selected, 0, selected.size() - 1);

    for (int i = 0; i < fibPos.size(); ++i)
        input[fibPos[i] - 1] = selected[i];
}

int main() {
    int size;
    cin >> size;

    vector<int> data(size);
    for (int i = 0; i < size; ++i)
        cin >> data[i];

    auto start = chrono::high_resolution_clock::now();
    fibonacciSort(data);
    auto end = chrono::high_resolution_clock::now();

    for (int val : data)
        cout << val << " ";
    cout << endl;

    chrono::duration<double, milli> elapsed = end - start;
    cout << elapsed.count() << " milliseconds" << endl;

    return 0;
}
