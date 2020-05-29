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

map<int,vector<int>> m;

void prime_fac(int t)
{
	map<int,int> mp;
	mp.clear();
	for(int i=2;i<=sqrt(t);++i)
	{
		if(t%i==0)
		{
			t/=i;
			mp[i]++;
			i--;
		}
	}
	if(t!=1)
	{
		mp[t]++;
	}
	for(auto it:mp)
	{
		int a = it.first, b = it.second;
		if(m.find(a)==m.end())
		{
			vector<int> v{b};
			m.insert(make_pair(a,v));
		}
		else
		{
			m[a].emplace_back(b);
		}
	}
}

int main()
{
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
		prime_fac(v[i]);
	}
	ll ans = 1;
	for(auto it:m)
	{
		int a = it.first;
		vector<int> vt = it.second;
		sort(vt.begin(),vt.end());
		if(vt.size()<n-1) continue;
		if(vt.size()==n-1) ans*=powl(a,vt[0]);
		if(vt.size()==n) ans*=powl(a,vt[1]);
	}
	cout << ans << endl;
	return 0;
}