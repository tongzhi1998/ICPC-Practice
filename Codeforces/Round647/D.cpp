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

long long n,k,m,a,b;

const int maxn = 5e5+10;

vector<int> graph[maxn];

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<m;++i)
	{
		cin>>a>>b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

	vector<int> ans(n+1,-1);
	vector<pair<int,int>> v(n);
	for(int i=0;i<n;++i)
	{
		cin>>a;
		v[i] = make_pair(a,i+1);
	}

	sort(v.begin(),v.end());

	// debug;
	// for(int i=0;i<n;++i)
	// {
	// 	cout << v[i].first << " " << v[i].second << endl;
	// }
	bool ok = true;
	for(int i=0;i<n;++i)
	{
		int from = v[i].second;
		set<int> color; color.clear();
		for(int j=0;j<graph[from].size();++j)
		{
			int to = graph[from][j];
			if(ans[to]==-1) continue;
			color.insert(ans[to]);
			// if(from == 1)
			// {
			// 	cout << "ans to is: " << ans[to] << endl;
			// }
		}
		int cnt = 0;
		while(true)
		{
			cnt++;
			if(color.find(cnt)==color.end())
			{
				if(cnt!=v[i].first)
				{
					//cout << cnt << " "  << i << " " << v[i].first << " " << v[i].second << endl;
					ok = false;
				}
				else
				{
					ans[from] = v[i].first;
				}
				break;
			}
		}
		if(!ok) break;
	}

	if(!ok)
	{
		cout << "-1" << endl;
	}
	else
	{
		for(int i=0;i<n;++i)
		{
			cout << v[i].second << " "; 
		}
		cout << endl;
	}
	return 0;
}