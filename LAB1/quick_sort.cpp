#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int divide(vector<int>& data, int start, int end) {
    int pivot = data[end];
    int index = start - 1;

    for(int current = start; current < end; current++) {
        if(data[current] <= pivot) {
            index++;
            swap(data[index], data[current]);
        }
    }
    swap(data[index + 1], data[end]);
    return index + 1;
}

void quickSort(vector<int>& data, int start, int end) {
    if (start < end) {
        int mid = divide(data, start, end);
        quickSort(data, start, mid - 1);
        quickSort(data, mid + 1, end);
    }
}

void processFile(const string& input_file, const string& output_file) {
    ifstream input(input_file);
    vector<int> values;
    int number;

    while (input >> number) {
        values.push_back(number);
    }
    input.close();

    auto begin = high_resolution_clock::now();
    quickSort(values, 0, values.size() - 1);
    auto finish = high_resolution_clock::now();

    auto timeTaken = duration_cast<milliseconds>(finish - begin);
    cout << "Sorted " << values.size() << " heights from " << input_file
         << " in " << timeTaken.count() << "ms" << endl;

    ofstream output(output_file);
    for (int val : values) {
        output << val << endl;
    }
    output.close();
}

int main() {
    processFile("heights_1000.txt", "sorted_heights_1000.txt");
    processFile("heights_5000.txt", "sorted_heights_5000.txt");
    processFile("heights_10000.txt", "sorted_heights_10000.txt");
    processFile("heights_50000.txt", "sorted_heights_50000.txt");

    return 0;
}
