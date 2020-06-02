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

long long n,t,h,u,m;

string s;

map<char,int> mp;
vector<pair<char,int>> v;

unordered_set<char> all;


bool cmp(pair<char,int>& a, pair<char,int>& b)
{
	return a.second<b.second;
}

int main()
{
	cin>>t;
	h = t;
	while(t--)
	{
		all.clear();
		cin>>u;
		mp.clear();
		v.clear();
		for(int i=0;i<10000;++i)
		{
			cin>>m>>s;
			if(s.length()==u)
			{
				mp[s[0]]++;
			}
			if(all.size()==10) continue;
			for(int j=0;j<s.size();++j)
			{
				all.insert(s[j]);
			}
		}
		string ans; ans.clear();
		
		for(auto it: all)
		{
			if(mp.find(it)==mp.end())
			{
				ans+=it;
				break;
			}
		}


		for(auto it: mp)
		{
			v.emplace_back(it.first,it.second);
		}

		sort(v.begin(),v.end(),cmp);

		for(int i=8;i>=0;--i)
		{
			ans+=v[i].first;
		}

		cout << "Case #" << h-t << ": " << ans << endl;
	}
	return 0;
}