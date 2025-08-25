#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[1001][1001]; 

int LCS(int i, int j) {
    if (i == s1.size() || j == s2.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i] == s2[j]) 
        return dp[i][j] = 1 + LCS(i+1, j+1);
    return dp[i][j] = max(LCS(i+1, j), LCS(i, j+1));
}

string getLCS() {
    int i=0, j=0;
    string ans="";
    while(i < s1.size() && j < s2.size()) {
        if(s1[i]==s2[j]) {
            ans.push_back(s1[i]);
            i++; j++;
        }
        else {
            if (LCS(i+1,j) > LCS(i,j+1)) i++;
            else j++;
        }
    }
    return ans;
}

int main() {
    s1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    s2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    memset(dp,-1,sizeof(dp));
    int len = LCS(0,0);
    string lcs = getLCS();
    cout << "LCS: " << lcs << "\nLength: " << len << endl;
}
