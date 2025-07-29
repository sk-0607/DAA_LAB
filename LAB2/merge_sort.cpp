#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
using namespace std;

struct Employee {
    int id;
    string name, department;
    float salary;
};

vector<Employee> readFromFile(const string& filename) {
    vector<Employee> data;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        Employee e;
        string salaryStr;
        stringstream ss(line);
        getline(ss, line, ','); e.id = stoi(line);
        getline(ss, e.name, ',');
        getline(ss, e.department, ',');
        getline(ss, salaryStr, ','); e.salary = stof(salaryStr);
        data.push_back(e);
    }
    return data;
}

void writeToFile(const vector<Employee>& data, const string& filename) {
    ofstream file(filename);
    for (auto& e : data)
        file << e.id << "," << e.name << "," << e.department << "," << e.salary << "\n";
}

void merge(vector<Employee>& data, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<Employee> L(data.begin() + left, data.begin() + mid + 1);
    vector<Employee> R(data.begin() + mid + 1, data.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        data[k++] = (L[i].id <= R[j].id) ? L[i++] : R[j++];
    while (i < n1) data[k++] = L[i++];
    while (j < n2) data[k++] = R[j++];
}

void mergeSort(vector<Employee>& data, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

int main() {
    vector<string> files = {
        "ascending_employees_5000.txt",
        "ascending_employees_10000.txt",
        "ascending_employees_20000.txt",
        "descending_employees_5000.txt",
        "descending_employees_10000.txt",
        "descending_employees_20000.txt",
        "random_employees_5000.txt",
        "random_employees_10000.txt",
        "random_employees_20000.txt"
    };

    for (const auto& file : files) {
        vector<Employee> data = readFromFile(file);
        auto start = chrono::high_resolution_clock::now();
        mergeSort(data, 0, data.size() - 1);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        cout << "Time to sort " << file << ": " << duration.count() << "s\n";

        string outputFile = "sorted_output_" + file;
        writeToFile(data, outputFile);
    }

    return 0;
}
