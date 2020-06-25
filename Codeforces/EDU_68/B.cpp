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

long long n,m,q;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>q;
	while(q--)
	{
		cin>>n>>m;
		vector<vector<char>> v(n);
		for(int i=0;i<n;++i)
		{
			v[i].resize(m);
		}
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				cin>>v[i][j];
			}
		}
		vector<int> cnt_h(n,0), cnt_v(m,0);

		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				if(v[i][j]=='.')
				{
					cnt_h[i]++;
					cnt_v[j]++;
				}
			}
		}
		int ans = n + m;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				ans = min(ans, cnt_h[i] + cnt_v[j] - (v[i][j] == '.'));
			}
		}
		cout << ans << endl;

	}

	return 0;
}