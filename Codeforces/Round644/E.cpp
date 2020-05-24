/*
	Author: tongzhi1007
	Submission: 81252002
	Time: May/24/2020 17:19
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

long long n,k,t;

const int maxn = 55;

int grid[maxn][maxn];
bool valid[maxn][maxn];

bool check(int x,int y)
{
	if(x==n-1||y==n-1) 
	{
		valid[x][y] = true;
		return true;
	}
	//bool hor = false, ver = false;
	
		if(valid[x+1][y])
		{
			valid[x][y] = true;
			return true;
		}
	
	
		if(valid[x][y+1])
		{
			valid[x][y] = true;
			return true;
		}
	return false;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				char c;
				cin>>c;
				grid[i][j] = c-'0';
				valid[i][j] = false;
			}
		}
		//cout << "HERE" << endl;
		bool flag = false;
		for(int i=n-1;i>=0;--i)
		{
			for(int j=n-1;j>=0;--j)
			{
				if(grid[i][j]==1)
				{
					if(check(i,j)==false)
					{
						//cout << "i is: " << i << " j is: " << j << endl; 
						cout << "NO" << endl;
						flag= true;
						break;
					}
				}

			}
			if(flag)
				break;
		}
		if(!flag)
		{
			cout << "YES" << endl;
		}
	}
	return 0;
}