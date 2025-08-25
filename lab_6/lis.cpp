#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = arr.size();
    vector<int> lis(n,1), prev(n,-1);

    int maxLen=0, lastIndex=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(arr[i]>arr[j] && lis[i]<lis[j]+1) {
                lis[i]=lis[j]+1;
                prev[i]=j;
            }
        }
        if(lis[i]>maxLen) {
            maxLen=lis[i];
            lastIndex=i;
        }
    }

    // reconstruct LIS
    vector<int> seq;
    for(int i=lastIndex; i!=-1; i=prev[i]) seq.push_back(arr[i]);
    reverse(seq.begin(), seq.end());

    cout<<"LIS: ";
    for(int x: seq) cout<<x<<" ";
    cout<<"\nLength: "<<maxLen<<endl;
}
