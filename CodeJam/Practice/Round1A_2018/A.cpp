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

long long n,t,h,r,c,v;

const int maxn = 110;

char grid[maxn][maxn];

int main()
{
	cin>>t;
	n = t;
	while(t--)
	{
		//memset(grid,0,sizeof(grid));
		cin>>r>>c>>h>>v;
		int cnt = 0;
		for(int i=0;i<r;++i)
		{
			for(int j=0;j<c;++j)
			{
				cin>>grid[i][j];
				if(grid[i][j]=='@') cnt++;
			}
		}
		bool flag = false;
		if(cnt%((h+1)*(v+1))!=0)
		{
			flag = true;
		}

		vector<pair<int,int>> hor;

		int each = cnt/(h+1);

		//cout << boolalpha << flag << endl;

		int prev = 0;
		int curr = 0;
		for(int i=0;i<r;++i)
		{
			for(int j=0;j<c;++j)
			{
				if(grid[i][j]=='@') curr++;
			}
			if(curr==each) 
			{
				hor.emplace_back(prev,i);
				prev = i+1;
				curr = 0;
			}
			else if(curr>each) 
			{
				flag = true;
				break;
			}
		}

		//cout << boolalpha << flag << endl;

		vector<pair<int,int>> ver;
		prev = 0;
		curr = 0;
		each = cnt/(v+1);
		for(int i=0;i<c;++i)
		{
			for(int j=0;j<r;++j)
			{
				if(grid[j][i]=='@') curr++;
			}
			if(curr==each) 
			{
				ver.emplace_back(prev,i);
				prev = i+1;
				curr = 0;
			}
			else if(curr>each) 
			{
				flag = true;
				break;
			}
		}

		if(flag)
		{
			cout << "Case #" << n-t << ": " << "IMPOSSIBLE" << endl;
			continue;
		}

		each = cnt/((h+1)*(v+1));

		// cout << boolalpha << flag << endl;
		// cout << each << endl;
		for(int i=0;i<h+1;++i)
		{
			for(int j=0;j<v+1;++j)
			{
				int x = hor[i].first, y = hor[i].second, w = ver[j].first, z = ver[j].second;
				int cur = 0;
				for(int q=x;q<=y;++q)
				{
					for(int f=w;f<=z;++f)
					{
						if(grid[q][f]=='@') cur++;
					}
				}
				if(cur!=each) flag = true;
			}
		}

		if(flag) cout << "Case #" << n-t << ": " << "IMPOSSIBLE" << endl;
		else cout << "Case #" << n-t << ": " << "POSSIBLE" << endl;
	}
	return 0;
}