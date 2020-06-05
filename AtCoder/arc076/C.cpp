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

long long n,k,r,c,x,y,z,w;

int on_which(int x,int y)
{
	if(x==0) return y;
	if(y==c) return c+x;
	if(x==r) return r+2*c-y;
	if(y==0) return 2*(r+c)-x;
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>r>>c>>n;
	vector<vector<int>> points;
	for(int i=0;i<n;++i)
	{
		cin>>x>>y>>z>>w;
		int one = on_which(x,y), two = on_which(z,w);
		if(one!=-1 && two!=-1){
			if(one>two) swap(one,two);
			points.emplace_back(vector<int>{one,two});
		}
	}

	sort(points.begin(),points.end());
	n = points.size();

	if(points.size()==0)
	{
		cout << "YES" << endl;
		return 0;
	}

	stack<int> s;
	int start = points[0][0], end = points[0][1];
	s.push(end);
	bool ok = true;
	for(int i=1;i<n;++i)
	{
		int curr_start = points[i][0], curr_end = points[i][1];
		while(!s.empty())
		{
			if(curr_start>s.top()) s.pop();
			else break;
		}
		if(s.empty()) s.push(curr_end);
		else
		{
			if(s.top()>curr_end) s.push(curr_end);
			else
			{
				ok = false;
				break;
			}
		}
	}
	if(!ok) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}