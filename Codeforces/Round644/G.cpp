/*
	Author: tongzhi1007
	Submission: 81281041
	Time: May/24/2020 17:56
*/


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

long long n,t,m,a,b;

const int maxn = 55;

int grid[maxn][maxn];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>a>>b;
		if(n*a!=m*b)
		{
			cout << "NO" << endl;
			continue;
		}
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				grid[i][j] = 0;
			}
		}
		int start = 0;
		for(int i=0;i<n;++i)
		{
			int end = (start+a)%m;
			if(start==end)
			{
				for(int j=0;j<m;++j)
				{
					grid[i][j] = 1;
				}
			}
			for(int j=start;j!=end;j = (j+1)%m)
			{
				grid[i][j] = 1;
			}
			start = end;
		}
		cout << "YES" << endl;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				cout << grid[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}