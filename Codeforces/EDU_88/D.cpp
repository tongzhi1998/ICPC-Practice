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

long long n,k;

const ll maxn = 1e5+10;

ll dp[maxn][62];

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	vector<ll> v(n+1);
	ll ans = 0;
	for(int i=1;i<=n;++i)
	{
		cin>>v[i];
	}
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=61;++j)
		{
			dp[i][j] = INT_MIN;
		}
	}
	for(int i=1;i<=n;++i)
	{
		dp[i][v[i]+30] = 0;
	}
	for(int i=2;i<=n;++i)
	{
		for(int j=0;j<=60;++j)
		{
			if(dp[i-1][j]==INT_MIN) continue;
			if(v[i]>=j-30)
			{
				dp[i][v[i]+30] = max(dp[i-1][j] + (j-30),dp[i][v[i]+30]);
			}
			else
			{
				dp[i][j] = max(dp[i-1][j] + v[i], dp[i][j]);
			}
		}
	}

	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=60;++j)
		{
			ans = max(ans,dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}