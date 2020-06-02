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

long long n,t,h,d;

map<ll,ll> mp;

int main()
{
	cin>>t;
	h = t;
	while(t--)
	{
		mp.clear();
		cin>>n>>d;
		vector<ll> v(n);
		ll mx = 0;
		for(int i=0;i<n;++i)
		{
			cin>>v[i];
			mx=max(mx,v[i]);
			mp[v[i]]++;
			//cout << v[i] << " "	;
		}
		// cout << endl;
		// cout << n << " " << d << endl;
		if(d==2)
		{
			bool flag = false;
			for(auto it: mp)
			{
				if(it.second>=2)
				{
					flag = true;
					break;
				}
			}
			if(flag) cout << "Case #" << h-t << ": " << "0" << endl;
			else cout << "Case #" << h-t << ": " << "1"<< endl;
		}
		else if(d==3)
		{
			bool flag = false;
			int ans = 2;
			for(auto it: mp)
			{
				if(it.second>=3)
				{
					//cout << "second is: " << it.second << endl;
					flag = true;
					break;
				}
				else if(it.second==2)
				{
					if(it.first!=mx) ans = 1;
				}
				else 
				{
					if(mp.find(2*it.first)!=mp.end())
					{
						ans = 1;
					}
				}
			}
			if(flag) cout << "Case #" << h-t << ": " << "0" << endl;
			else cout << "Case #" << h-t << ": " << ans << endl;
		}
	}
	
	return 0;
}