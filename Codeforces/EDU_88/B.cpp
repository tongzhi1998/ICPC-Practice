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

const int maxn = 110;
const int maxm = 1010;

char grid[maxn][maxm];

long long n,k,x,y,m,t;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>x>>y;
		ll cnt = 0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				cin>>grid[i][j];
				if(grid[i][j]=='.') cnt++;
			}
		}
		if(2*x<=y)
		{
			cout << x*cnt << endl;
			continue;
		}
		ll cnt_2 = 0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m-1;++j)
			{
				if(grid[i][j]=='.' && grid[i][j+1]=='.')
				{
					cnt_2++;
					j++;
				}
			}
		}
		cout << cnt_2*y+(cnt-2*cnt_2)*x << endl;
	}
	return 0;
}