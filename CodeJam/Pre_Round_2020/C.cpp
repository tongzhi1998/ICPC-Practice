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

long long n,t;

const int maxn = 1010;

bool cmp(pair<pair<int,int>,int>& a, pair<pair<int,int>,int>& b)
{
	return a.first.first < b.first.first;
}

int main()
{
	cin>>t;
	int h = t;
	while(t--)
	{
		cin>>n;
		vector<pair<pair<int,int>,int>> v(n);
		vector<int> pick(n,0);
		for(int i=0;i<n;++i)
		{
			int a,b;
			cin>>a>>b;
			v[i].first.first = a;
			v[i].first.second = b;
			v[i].second = i;
		}
		sort(v.begin(),v.end(),cmp);
		pick[0] = 1;
		int ec = v[0].first.second;
		for(int i=1;i<n;++i)
		{
			if(v[i].first.first>=ec)
			{
				pick[i] = 1;
				ec = max(ec,v[i].first.second);
			}
		}
		int ej = 0;
		bool flag = true;
		for(int i=1;i<n;++i)
		{
			if(pick[i]==0)
			{
				if(v[i].first.first<ej)
				{
					flag = false;
					break;
				}
				else
				{
					pick[i] = 2;
					ej = max(ej,v[i].first.second);
				}
			}
		}
		if(!flag)
		{
			cout << "Case #" << h-t << ": IMPOSSIBLE" << endl;
		}
		else
		{
			cout << "Case #" << h-t << ": ";
			vector<int> ans(n);
			for(int i=0;i<n;++i)
			{
				ans[v[i].second] = pick[i];
			}
			for(int i=0;i<n;++i)
			{
				if(ans[i]==1)
				{
					cout << "C";
				}
				else
				{
					cout << "J";
				}
			}
			cout << endl;
		}
	}
	return 0;
}