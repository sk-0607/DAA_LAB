#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << "Input:" << endl;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    int maxSum = arr[0];
    int minLength = n + 1;
    int startIndex = 0, endIndex = 0;

    for(int i = 0; i < n; ++i) {
        int currentSum = 0;
        for(int j = i; j < n; ++j) {
            currentSum += arr[j];
            if(currentSum > maxSum || (currentSum == maxSum && (j - i + 1) < minLength)) {
                maxSum = currentSum;
                minLength = j - i + 1;
                startIndex = i;
                endIndex = j;
            }
        }
    }

    cout << "Output:" << endl;
    for(int i = startIndex; i <= endIndex; ++i)
        cout << arr[i] << endl;

    return 0;
}
