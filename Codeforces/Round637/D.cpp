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

vector<string> nums{"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

const int maxn = 2010;

bool dp[maxn][maxn];

int cost[maxn][10];

int compute(string from, string to)
{
	int cnt = 0;
	for(int i=0;i<7;++i)
	{
		if(from[i]=='1' && to[i]=='0')
			return -1;
		if(from[i]=='0' && to[i]=='1')
			cnt++;
	}
	return cnt;
}

int main()
{
	cin>>n>>k;
	vector<string> v(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}
	for(int i=0;i<maxn;++i)
	{
		for(int j=0;j<maxn;++j)
		{
			dp[i][j] = false;
		}
	}

	for(int i=0;i<n;++i)
	{
		for(int j=9;j>=0;--j)
		{
			cost[i][j] = compute(v[i],nums[j]);
		}
	}

	dp[n][0] = true;

	for(int i=n-1;i>=0;--i)
	{
		for(int j=0;j<=k;++j)
		{
			for(int k=9;k>=0;--k)
			{
				int c = cost[i][k];
				if(c==-1) continue;
				if(j-c>=0 )
				{
					dp[i][j] |= dp[i+1][j-c];
				}
			}
		}
	}

	if(!dp[0][k])
	{
		cout << "-1" << endl;
		return 0;
	}

	string ans;

	for(int i=0;i<n;++i)
	{
		for(int j=9;j>=0;--j)
		{
			int c = cost[i][j];
			if(c==-1) continue;
			if( !(k-c>=0 && dp[i+1][k-c] )) continue;
			ans+=j+'0';
			k-=c;
			break;
		}
	}

	cout << ans << endl;


	return 0;
}