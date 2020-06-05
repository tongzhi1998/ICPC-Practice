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

long long n,t;

const int maxn = 2010;
const int maxa = 27;

int l[maxn][maxa],r[maxn][maxa], cnt[maxa];

int main()
{
	cin>>t;
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=0;i<=n;++i)
		{
			for(int j=0;j<maxa;++j)
			{
				l[i][j] = 0;
				r[i][j] = 0;
			}
		}
		vector<int> v(n);
		int ans = 0;
		for(int i=0;i<n;++i)
		{
			cin>>v[i];
			cnt[v[i]]++;
		}
		for(int i=0;i<n;++i)
		{
			if(i==0)l[i][v[i]]++;
			else
			{
				for(int j=0;j<maxa;++j)
				{
					l[i][j] = l[i-1][j];
				}
				l[i][v[i]]++;
			}
		}
		for(int i=n-1;i>=0;--i)
		{
			if(i==n-1)r[i][v[i]]++;
			else
			{
				for(int j=0;j<maxa;++j)
				{
					r[i][j] = r[i+1][j];
				}
				r[i][v[i]]++;
			}
		}
		for(int a = 0; a<n ; ++a)
		{
			for(int b = a+1; b<n;++b)
			{
				int side = 0, middle = 0;
				for(int j=0;j<maxa;++j)
				{
					side = max(side,min(l[a][j],r[b][j]));
					middle = max(middle,l[b-1][j]-l[a][j]);
				}
				ans = max(ans,side*2+middle);
			}
		}


		for(int i=0;i<=maxa;++i)
		{
			ans = max(ans,cnt[i]);
		}
		cout << ans << endl;
	}
	return 0;
}