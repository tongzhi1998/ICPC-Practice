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

long long n,t,h;

const int maxn = 110;

int dp[maxn][maxn];

int main()
{
	cin>>t;
	h=t;
	while(t--)
	{
		for(int i=0;i<maxn;++i)
		{
			for(int j=0;j<maxn;++j)
			{
				dp[i][j] = inf;
			}
		}
		cin>>n;
		vector<int> ants(n+1);
		for(int i=1;i<=n;++i)
		{
			cin>>ants[i];
		}
		int ans = 1;
		dp[1][1] = ants[1];
		for(int i=2;i<=n;++i)
		{
			dp[i][1] = min(dp[i-1][1],ants[i]);
		}

		for(int j=2;j<=n;++j)
		{
			for(int i=j;i<=n;++i)
			{
				dp[i][j] = dp[i-1][j];
				for(int k=i-1;k>=1;--k)
				{
					if(k<j-1) break;
					if(ants[i]*6>=dp[k][j-1] && dp[k][j-1]!=-1) 
						dp[i][j] = min(dp[i][j],dp[k][j-1]+ants[i]);
					if(dp[i][j]!=inf) ans = j;
				}
			}
		}
		cout << "Case #" << h-t << ": " << ans << endl;
	}

	return 0;
}