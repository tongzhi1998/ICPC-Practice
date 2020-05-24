/*
	Author: day_dream
	Submission: 80178146
	Time: May/15/2020 01:30
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
/* Data Structure */
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>

using namespace std;

#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fLL
#define debug cerr << "======= GOT_HERE ======\n"
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int,int> mii;
typedef map<long long,long long> mll;
typedef set<int> si;
typedef set<long long> sll;

int n,k,t;

const int maxn = 1e6+10;

int dp[maxn][2];
int sum[maxn];


int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=0;i<=n+1;++i)
		{
			dp[i][0] = 0;
			dp[i][1] = 0;
			sum[i] = 0;
		}
		string s;
		cin>>s;
		sum[0] = s[0]-'0';
		for(int i=1;i<n;++i)
		{
			sum[i] = sum[i-1]+s[i]-'0';
		}
		// if(k==1)
		// {
		// 	cout << max(min(sum[n-1]-1,n-sum[n-1]),0) << endl;
		// 	continue;
		// }
		if(s[0]=='0')
		{
			dp[0][0] = 0;
			dp[0][1] = 1;
		}
		else
		{
			dp[0][1] = 0;
			dp[0][0] = 1;
		}
		for(int i=1;i<n;++i)
		{
			if(s[i]=='1')
			{
				if(i-k>=0)
				{
					dp[i][1] = min(dp[i-k][1]+sum[i-1]-sum[i-k],sum[i-1]);
				}
				else
				{
					dp[i][1] = sum[i-1];
				}
				dp[i][0] = min(dp[i-1][0],dp[i-1][1])+1;

			}
			else
			{
				if(i-k>=0)
				{
					dp[i][1] = min(dp[i-k][1]+sum[i-1]-sum[i-k]+1,sum[i-1]+1);
				}
				else
				{
					dp[i][1] = sum[i-1]+1;
				}
				dp[i][0] = min(dp[i-1][0],dp[i-1][1]);
			}
		}
		// debug;
		// for(int i=0;i<n;++i)
		// {
		// 	cout << dp[i][0] << " ";
		// }
		// cout << endl;
		// for(int i=0;i<n;++i)
		// {
		// 	cout << dp[i][1] << " ";
		// }
		// cout << endl;
		cout << min(dp[n-1][0],dp[n-1][1]) << endl;
	}
	return 0;
}