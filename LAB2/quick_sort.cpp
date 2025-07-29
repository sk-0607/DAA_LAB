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

int partition(vector<Employee>& data, int low, int high) {
    int pivot = data[high].id;
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (data[j].id < pivot)
            swap(data[++i], data[j]);
    }
    swap(data[i + 1], data[high]);
    return i + 1;
}

void quickSort(vector<Employee>& data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
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
        quickSort(data, 0, data.size() - 1);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        cout << "Time to sort " << file << ": " << duration.count() << "s\n";

        string outputFile = "sorted_output_" + file;
        writeToFile(data, outputFile);
    }

    return 0;
}
