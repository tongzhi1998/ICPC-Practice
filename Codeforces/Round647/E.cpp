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

long long n,k,t,p;

const int MOD = 1e9+7;

int powMod(int u, int v) 
{		
	int res = 1;		
	while (v) 
	{		
		if (v & 1) res = (ll)res * u % MOD;		
		v >>= 1;		
		u = (ll) u * u % MOD;		
	}		
	return res;		
}		

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n>>p;

		vector<ll> v(n);
		vector<ll> lft, rht;
		for(int i=0;i<n;++i)
		{
			cin>>v[i];
		}

		if(p==1)
		{
			if(n%2==0)
			{
				cout << "0" << endl;
			}
			else
			{
				cout << "1" << endl;
			}
			continue;
		}

		sort(v.begin(),v.end(),greater<ll>());
		ll offset = 0;
		lft.emplace_back(v[0]);
		offset = 1;
		bool flag = false;
		bool l = true;
		int idx = -1;
		for(int i=1;i<n;++i)
		{
			if(offset<=0)
			{
				ll diff = v[i-1]-v[i];
				for(ll j=0;j<diff;++j)
				{
					offset*=p;
					if(abs(offset)>=n)
					{
						flag = true;
						break;
					}
				}
				if(flag)
				{
					idx = i;
					l = true;
					break;
				}
				offset++;
				lft.emplace_back(v[i]);
			}
			else
			{
				ll diff = v[i-1]-v[i];
				for(ll j=0;j<diff;++j)
				{
					offset*=p;
					if(abs(offset)>=n)
					{
						flag = true;
						break;
					}
				}
				if(flag)
				{
					idx = i;
					l = false;
					break;
				}
				offset--;
				rht.emplace_back(v[i]);
			}
		}

		if(idx!=-1 && l)
		{
			for(int i=idx;i<n;++i)
			{
				lft.emplace_back(v[i]);
			}
		}

		if(idx!=-1 && !l)
		{
			for(int i=idx;i<n;++i)
			{
				rht.emplace_back(v[i]);
			}
		}

		// debug;
		// for(int i=0;i<lft.size();++i)
		// {
		// 	cout << lft[i] << " ";
		// }
		// cout << endl;

		ll ans = 0;
		for(int i=0;i<lft.size();++i)
		{
			ans+=powMod(p,lft[i]); ans%=MOD;
		}
		for(int i=0;i<rht.size();++i)
		{
			ans+=MOD;
			ans-=powMod(p,rht[i]);
			ans%=MOD;
		}
		cout << ans << endl;
	}
	return 0;
}