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

long long n,t,r,g,b,a;

ll calc(ll x,ll y, ll z)
{
	return powl(abs(x-y),2)+powl(abs(y-z),2)+powl(abs(z-x),2);
}


int main()
{
	cin>>t;
	while(t--)
	{
		cin>>r>>g>>b;
		// r>=g>=b
		set<ll> sr, sb,sg;
		for(int i=0;i<r;++i)
		{
			cin>>a;
			sr.insert(a);
		}
		for(int i=0;i<g;++i)
		{
			cin>>a;
			sg.insert(a);
		}
		for(int i=0;i<b;++i)
		{
			cin>>a;
			sb.insert(a);
		}
		//cout << "here" << endl;

		// r>=g>=b
		ll ans = LLONG_MAX;
		for(auto it: sr)
		{
			ll temp = it;
			auto it2 = (sg.lower_bound(temp));
			if(*it2!=*sg.begin())
			{
				--it2;
			}
			ll temp2  = *it2;
			auto it3 = (sb.lower_bound(temp2));
			if(*it3!=*sb.begin())
			{
				--it3;
			}
			ll temp3 = *it3;
			ans = min(ans,calc(temp,temp2,temp3));
		}
		//cout << "here1" << endl;
		// r>=b>=g
		for(auto it: sr)
		{
			ll temp = it;
			auto it2 = (sb.lower_bound(temp));
			if(*it2!=*sb.begin())
			{
				--it2;
			}
			ll temp2  = *it2;

			auto it3 = (sg.lower_bound(temp2));
			if(*it3!=*sg.begin())
			{
				--it3;
			}
			ll temp3 = *it3;
			ans = min(ans,calc(temp,temp2,temp3));
		}

		// b>=r>=g
		for(auto it: sb)
		{
			ll temp = it;
			//cout << temp << endl;
			auto it2 = (sr.lower_bound(temp));
			//cout << *it2 << endl;
			if(*it2!=*sr.begin())
			{
				--it2;
			}
			ll temp2  = *it2;
			
			auto it3 = (sg.lower_bound(temp2));
			if(*it3!=*sg.begin())
			{
				--it3;
			}
			ll temp3 = *it3;
			ans = min(ans,calc(temp,temp2,temp3));
		}

		// b>=g>=r
		for(auto it: sb)
		{
			ll temp = it;
			auto it2 = (sg.lower_bound(temp));
			if(*it2!=*sg.begin())
			{
				--it2;
			}
			ll temp2  = *it2;
			auto it3 = (sr.lower_bound(temp2));
			if(*it3!=*sr.begin())
			{
				--it3;
			}
			ll temp3 = *it3;
			ans = min(ans,calc(temp,temp2,temp3));
		}

		// g>=r>=b
		for(auto it: sg)
		{
			ll temp = it;
			auto it2 = (sr.lower_bound(temp));
			if(*it2!=*sr.begin())
			{
				--it2;
			}
			ll temp2 = *it2;
			auto it3 = (sb.lower_bound(temp2));
			if(*it3!=*sb.begin())
			{
				--it3;
			}
			ll temp3 = *it3;
			ans = min(ans,calc(temp,temp2,temp3));
		}
		//g>=b>=r
		for(auto it: sg)
		{
			ll temp = it;
			auto it2 = (sb.lower_bound(temp));
			if(*it2!=*sb.begin())
			{
				--it2;
			}
			ll temp2  = *it2;
			auto it3 = (sr.lower_bound(temp2));
			if(*it3!=*sr.begin())
			{
				--it3;
			}
			ll temp3 = *it3;
			ans = min(ans,calc(temp,temp2,temp3));
		}

		cout << ans << endl;
	}
	return 0;
}