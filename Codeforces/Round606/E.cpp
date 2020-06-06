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
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
 
int t,n,m,s,f;
 
const int maxn = 2e5+20;
 
bool visited[maxn];
 
long long cnt1 = 0, cnt2 = 0, cnt3 = 0;
 
vector<int> adj[maxn];
 
void bfs(int start)
{
	bool flags = false;
	bool flagf = false;
	if(visited[start]) return;
	queue<int> q;
	unordered_set<int> st;
	q.push(start);
	st.insert(start);
	visited[start] = true;
	while(!q.empty())
	{
		int to = q.front();
		q.pop();
		if(to==s)
		{
			flags = true;
		}
		else if(to==f)
		{
			flagf = true;
 
		}
		else
		{
			for(int i=0;i<adj[to].size();++i)
			{
				if(st.find(adj[to][i])==st.end())
				{
					q.push(adj[to][i]);
					st.insert(adj[to][i]);
					visited[adj[to][i]] = true;
				}
			}
		}
	}
	if(flags && flagf)
	{
		cnt2+=st.size()-1;
	}
	else if(flags)
	{
		cnt1+=st.size()-1;
	}
	else
	{
		cnt3+=st.size()-1;
	}
}
 
int main()
{
	cin>>t;
	while(t--)
	{
		memset(visited,false,sizeof(visited));
		for(int i=1;i<=n;++i)
		{
			adj[i].clear();
		}
		cin>>n>>m>>s>>f;
		for(int i=0;i<m;++i)
		{
			int a,b;
			cin>>a>>b;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		visited[s] = true;
		visited[f] = true;
		cnt1 = 0;
		cnt2 = 0;
		cnt3 = 0;
		for(int i=1;i<=n;++i)
		{
			bfs(i);
		}
		//cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;
		cout << cnt1*cnt3 << endl;
	}
	return 0;
}