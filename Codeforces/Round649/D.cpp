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

long long n,m,k,a,b;

const int maxn = 1e5+20;

vector<int> graph[maxn];

int dist[maxn];

void bfs(int from)
{
	queue<int> q;
	set<int> visited;
	dist[from] = 0;
	q.push(from);
	visited.insert(from);
	while(!q.empty())
	{
		int to = q.front();
		q.pop();
		for(int i=0;i<graph[to].size();++i)
		{
			int tto = graph[to][i];
			if(visited.find(tto)==visited.end())
			{
				visited.insert(tto);
				dist[tto] = dist[to]+1;
				q.push(tto);
			}
		}
	}
}

vector<int> bfs2(int start)
{
	vector<int> ans;
	queue<int> q;
	set<int> visited;
	q.push(start);
	ans.emplace_back(start);
	bool flag = false;
	while(!q.empty())
	{
		int from = q.front();
		q.pop();
		int idx = -1;
		int mn = inf;
		for(int i=0;i<graph[from].size();++i)
		{
			int to = graph[from][i];
			//cout << "from is: " << from << " to is: " << to << endl;
			if(visited.find(to)==visited.end())
			{
				if(to==start) // go back
				{
					if(ans.size()>=3)
					{
						flag = true;
						return ans;
					}
					else
					{
						continue;
					}
				}
				else if(graph[to].size()!=1 && dist[to]<mn)
				{
					mn = dist[to];
					idx = to;
				}
			}
		}

		if(idx!=-1)
		{
			visited.insert(idx);
			ans.emplace_back(idx);
			q.push(idx);
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;
	int target = (k+1)/2;
	for(int i=0;i<m;++i)
	{
		cin>>a>>b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	for(int i=0;i<=n;++i)
	{
		dist[i] = inf;
	}
	bfs(1);
	int mn = 0, cnt = 0;
	for(int i=1;i<=n;++i)
	{
		if(dist[i]%2==0) cnt++;
	}
	if(cnt>=target) // independent set
	{
		cout << "1" << endl;
		vector<int> ans;
		for(int i=1;i<=n;++i)
		{
			if(dist[i]%2==0)
			{
				ans.emplace_back(i);
				if(ans.size()==target){
					break;
				}
			}
		}

		for(int i=0;i<ans.size();++i)
		{
			cout << ans[i] <<  " ";
		}
		cout << endl;
	}
	else
	{
		cout << "2" << endl;
		vector<int> ans = bfs2(1);
		cout << ans.size() << endl;
		for(int i=0;i<ans.size();++i)
		{
			cout << ans[i] <<  " ";
		}
		cout << endl;
	}
	return 0;
}