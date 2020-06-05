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


const int maxn = 2e5+10;

int dist[maxn];

vector<int> graph[maxn];

int dfs(int start,int d, int pa)
{

	if(graph[start].size()==1 && pa!=-1)
	{
		dist[start] = d;
		return 1;
	}
	int res = d;
	int sz = 0;
	for(int i=0;i<graph[start].size();++i)
	{
		if(graph[start][i]==pa) continue;
		sz+=dfs(graph[start][i],d+1,start);
	}
	res-=sz;
	dist[start] = res;
	return sz+1;
}

int main()
{
	cin>>n>>k;
	for(int i=0;i<n-1;++i)
	{
		int a,b;
		cin>>a>>b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	dfs(1,0,-1);
	// for(int i=1;i<=n;++i)
	// {
	// 	cout << dist[i] << " ";
	// }
	// cout << endl;
	vector<int> res;
	for(int i=1;i<=n;++i)
	{
		res.emplace_back(dist[i]);
	}

	sort(res.begin(),res.end(),std::greater<int>());

	ll ans = 0;
	for(int i=0;i<k;++i)
	{
		ans+=res[i];
	}
	cout << ans << endl;
	return 0;
}