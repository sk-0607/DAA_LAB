#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

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
        stringstream ss(line);
        string salaryStr;
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

void selectionSort(vector<Employee>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (data[j].id < data[minIdx].id)
                minIdx = j;
        swap(data[i], data[minIdx]);
    }
}

void processFile(const string& filename) {
    vector<Employee> data = readFromFile(filename);

    auto start = high_resolution_clock::now();
    selectionSort(data);
    auto end = high_resolution_clock::now();

    cout << "Time to sort " << filename << ": " << duration<double>(end - start).count() << "s\n";

    string outFile = "sorted_" + filename;
    writeToFile(data, outFile);
    //cout << "Output saved to: " << outFile << "\n";
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

    // Iterate through the list of files and process each one
    for (const auto& file : files) {
        processFile(file);
    }

    return 0;
}
