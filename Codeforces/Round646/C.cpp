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

long long n,k,t,x,a,b;

const string A = "Ayush";
const string B = "Ashish";

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		vector<vector<int>> graph;
		if(n==1)
		{
			cout << A << endl;
			continue;
		}
		graph.resize(n+1);
		for(int i=0;i<n-1;++i)
		{
			cin>>a>>b;
			graph[a].emplace_back(b);
			graph[b].emplace_back(a);
		}
		//cout << x << " " << graph[x].size() << endl;
		if(graph[x].size()==1 || graph[x].size()==0)
		{
			cout << A << endl;
			continue;
		}
		int sz = n-3;
		//cout << "sz is: " << sz << endl;
		if(sz%2==1)
		{
			cout << A << endl;
		}
		else
		{
			cout << B << endl;
		}
	}
	return 0;
}