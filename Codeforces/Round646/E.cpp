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

long long n,k,a,b,c;

ll ans = 0;

set<ll> visited;

vector<vector<ll>> v;
vector<vector<ll>> graph;

ll mn = INF;

ll mn_flag = INF;

bool flag = false;


ll bfs(ll rt, ll cost)
{
	ll num = ((v[rt][1] == v[rt][2]) ? 0LL : 1LL);
	cost = min(cost,v[rt][0]);
	for(int i=0;i<graph[rt].size();++i)
	{
		ll to = graph[rt][i];
		if(visited.find(to)==visited.end())
		{
			visited.insert(to);
			num+=bfs(to,min(v[to][0],cost));
		}
	}
	if(num==1 && rt!=1)
	{
		return 1LL;
	}
	else
	{
		ans+=cost*num;
		return 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	v.resize(n+1);
	visited.clear();
	int cnt1 = 0, cnt2 = 0;
	for(int i=1;i<=n;++i)
	{
		cin>>a>>b>>c;
		v[i].emplace_back(a);
		v[i].emplace_back(b);
		v[i].emplace_back(c);
		if(b==1) cnt1++;
		if(c==1) cnt2++;
	}
	graph.resize(n+1);
	for(int i=0;i<n-1;++i)
	{
		cin>>a>>b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	if(cnt1!=cnt2)
	{
		cout << "-1" << endl;
		return 0;
	}
	visited.insert(1);
	bfs(1,v[1][0]);
	cout << ans << endl;
	return 0;
}