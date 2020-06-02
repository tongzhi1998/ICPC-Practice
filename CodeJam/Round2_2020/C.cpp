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

int n,t,h,x,y;

int gcd(int a, int b)
{
  return b==0?a:gcd(b,a%b);
}

int lcm(int a, int b)
{
  return (a*b/gcd(a,b));
}

int main()
{
	cin>>t;
	h = t;
	while(t--)
	{
		cin>>n;
		map<pair<int,int>,int> mp;
		vector<pair<int,int>> v;
		for(int i=0;i<n;++i)
		{
			cin>>x>>y;
			v.emplace_back(x,y);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();++i)
		{
			for(int j=i+1;j<v.size();++j)
			{
				int x1 = v[i].first, y1 = v[i].second;
				int x2 = v[j].first, y2 = v[j].second;
				mp[make_pair((y2-y1)/gcd(abs(y2-y1),abs(x2-x1)),(x2-x1)/(gcd(abs(y2-y1),abs(x2-x1))))]++;

			}
		}

		int ans = 0;
		for(auto it: mp)
		{
			ans = max(ans,it.second+1);
		}

		ans = min(n,max(ans,min(n,4)));

		cout << "Case #" << h-t << ": " << ans << endl;
	}
	return 0;
}