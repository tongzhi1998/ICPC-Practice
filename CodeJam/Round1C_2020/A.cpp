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

long long n,t,h,x,y;

string m;

int main()
{
	cin>>t;
	h = t;
	while(t--)
	{
		cin>>x>>y;
		cin>>m;
		n = m.length();
		vector<int> dp(n);
		int cx = x, cy = y;
		for(int i=0;i<n;++i)
		{
			if(m[i]=='N')
			{
				cy++;
			}
			else if(m[i]=='S')
			{
				cy--;
			}
			else if(m[i]=='E')
			{
				cx++;
			}
			else
			{
				cx--;
			}
			dp[i] = abs(cx)+abs(cy);
		}
		int ans = -1;
		for(int i=0;i<n;++i)
		{
			if(dp[i]<=i+1)
			{
				ans = i+1;
				break;
			}
		}
		if(ans!=-1) cout << "Case #" << h-t << ": " << ans << endl;
		else cout << "Case #" << h-t << ": " << "IMPOSSIBLE" << endl;
	}
	return 0;
}