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

long long n,k,t;

const int maxn = 1e5+10;

int dp[maxn];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> v(n+1);
		for(int i=1;i<=n;++i)
		{
			cin>>v[i];
			dp[i] = 1;
		}
		
		for(int i=1;i<=n;++i)
		{
			for(int j=i<<1;j<=n;j+=i)
			{
				if(v[j]>v[i])
				{
					dp[j] = max(dp[j],dp[i]+1);
				}
			}
		}

		int ans = 0;
		for(int i=1;i<=n;++i)
		{
			ans = max(ans,dp[i]);
		}

		cout << ans << endl;

	}
	return 0;
}