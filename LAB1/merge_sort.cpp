#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

void merge(vector<int>& list, int left, int mid, int right) {
    int lenA = mid - left + 1;
    int lenB = right - mid;

    vector<int> A(lenA), B(lenB);

    for (int i = 0; i < lenA; ++i)
        A[i] = list[left + i];
    for (int j = 0; j < lenB; ++j)
        B[j] = list[mid + 1 + j];

    int idxA = 0, idxB = 0, mergedIdx = left;

    while (idxA < lenA && idxB < lenB) {
        if (A[idxA] <= B[idxB]) {
            list[mergedIdx++] = A[idxA++];
        } else {
            list[mergedIdx++] = B[idxB++];
        }
    }

    while (idxA < lenA)
        list[mergedIdx++] = A[idxA++];

    while (idxB < lenB)
        list[mergedIdx++] = B[idxB++];
}

void mergeSort(vector<int>& list, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(list, left, middle);
        mergeSort(list, middle + 1, right);
        merge(list, left, middle, right);
    }
}

void sortPages(const string& input_file, const string& output_file) {
    ifstream fileIn(input_file);
    vector<int> pageCounts;
    int page;

    while (fileIn >> page) {
        pageCounts.push_back(page);
    }
    fileIn.close();

    auto begin = high_resolution_clock::now();
    mergeSort(pageCounts, 0, pageCounts.size() - 1);
    auto finish = high_resolution_clock::now();

    auto timeTaken = duration_cast<milliseconds>(finish - begin);
    cout << "Sorted " << pageCounts.size() << " pages from " << input_file
         << " in " << timeTaken.count() << " ms" << endl;

    ofstream fileOut(output_file);
    for (int p : pageCounts) {
        fileOut << p << endl;
    }
    fileOut.close();
}

int main() {
    sortPages("pages_1000.txt", "sorted_pages_1000.txt");
    sortPages("pages_5000.txt", "sorted_pages_5000.txt");
    sortPages("pages_10000.txt", "sorted_pages_10000.txt");
    sortPages("pages_50000.txt", "sorted_pages_50000.txt");

    return 0;
}
