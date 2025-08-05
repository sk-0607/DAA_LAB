#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& NetProfit)
{
	int n=NetProfit.size();
	if(n==0) return 0;
	if(n==1) return max(0,NetProfit[0]);

	vector<int> dp(n);
	dp[0]=max(0,NetProfit[0]);
	dp[1]=max(dp[0],NetProfit[1]);

	for(int i=2;i<n;i++)
	{
		dp[i]=max(dp[i-1],dp[i-2]+NetProfit[i]);
	}

	return dp[n-1];
}

int main()
{
	int n;
	cout<<"Enter array size: ";
	cin>>n;
	vector<int> NetProfit(n);
	for(int i=0;i<n;i++)
	{
		cin>>NetProfit[i];
	}
	int maxsum=maxProfit(NetProfit);
	cout<<"Maximum Total Profit: "<<maxsum<<endl;
}
