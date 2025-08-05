#include <iostream>
#include <string>
using namespace std;

int findMax(const string& s, int l, int r) {
    if (l == r)
        return s[l] - '0';
    int m = (l + r) / 2;
    int leftMax = findMax(s, l, m);
    int rightMax = findMax(s, m + 1, r);
    return max(leftMax, rightMax);
}

int getMaxDigit(const string& s) {
    return findMax(s, 0, s.length() - 1);
}

int main() {
    string input;
    cin >> input;

    for (char c : input) {
        if (!isdigit(c)) {
            cout << "Invalid" << endl;
            return 1;
        }
    }

    int maxDigit = getMaxDigit(input);
    if (maxDigit < 8)
        cout << "Invalid" << endl;
    else
        cout << maxDigit << endl;

    return 0;
}
