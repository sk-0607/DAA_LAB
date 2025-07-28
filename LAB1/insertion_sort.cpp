#include <iostream> 
#include <fstream> 
#include <vector> 
#include <chrono> 
 
using namespace std; 
using namespace chrono; 
 
void insertionSort(vector<int>& arr) { 
    for(int i = 1; i < arr.size(); i++) { 
        int key = arr[i]; 
        int j = i - 1; 
        while(j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j--; 
        } 
        arr[j + 1] = key; 
    } 
} 
 
void sortFile(string input_file,string output_file) { 
    
    ifstream in(input_file); 
    vector<int> data; 
    int num; 
 
    while(in>>num) { 
        data.push_back(num); 
    } 
    in.close(); 
 
    auto start=high_resolution_clock::now(); 
    insertionSort(data); 
    auto end=high_resolution_clock::now(); 
 
    auto duration=duration_cast<milliseconds>(end-start); 
    cout<<"Sorted "<<data.size()<<" items from "<<input_file<<" in "<<duration.count()<<" ms"<<endl; 
 
    ofstream out(output_file); 
    for(int i = 0; i < data.size(); i++) { 
        out<<data[i]<<endl; 
    } 
    out.close(); 
} 
 
int main() {

    sortFile("input_1000.txt","sorted_output_1000.txt"); 
    sortFile("input_5000.txt","sorted_output_5000.txt"); 
    sortFile("input_10000.txt","sorted_output_10000.txt"); 
    sortFile("input_50000.txt","sorted_output_50000.txt"); 
 
    return 0; 
} 