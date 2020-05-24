/*
	Author: day_dream
	Submission: 80193572
	Time: May/15/2020 08:42
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

long long n,m,t;

const ll maxn = 101;

ll dp[maxn][maxn];

ll ans = LLONG_MAX;

ll grid[maxn][maxn];

void calc(int x, int y)
{
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			dp[i][j] = LLONG_MAX;

	ll origin = grid[x][y]-x-y;
	if(origin>grid[0][0]) return;
	dp[0][0] = grid[0][0] - origin;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(i==0 && j==0) continue;
			if(grid[i][j]<origin+i+j) continue;
			if(i-1>=0 && dp[i-1][j]!=LLONG_MAX)
			{
				dp[i][j] = min(dp[i][j],dp[i-1][j]+grid[i][j]-origin-i-j);
			}
			if(j-1>=0 && dp[i][j-1]!=LLONG_MAX)
			{
				dp[i][j] = min(dp[i][j],dp[i][j-1]+grid[i][j]-origin-i-j);
			}
		}

	}
	ans = min(ans,dp[n-1][m-1]);
}

int main()
{
	cin>>t;
	while(t--)
	{
		ans = LLONG_MAX;
		cin>>n>>m;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				cin>>grid[i][j];
			}
		}
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				calc(i,j);
			}
		}
		cout << ans << endl;
	}
	return 0;
}