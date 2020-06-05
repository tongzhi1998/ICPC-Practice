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

const int maxn = 9;

char grid[maxn][maxn];

int pos[3];

int main()
{
	cin>>t;
	while(t--)
	{
		for(int i=0;i<9;++i)
		{
			for(int j=0;j<9;++j)
			{
				cin>>grid[i][j];
			}
		}

		for(int i=0;i<3;++i)
		{
				for(int j=0;j<3;++j)
				{
					bool flag = false;
					for(int k=3*i;k<3*i+3;++k)
					{
						if(grid[k][j]=='1')
						{
							grid[k][(j+1)%3] = '1';
							flag = true;
							break;
						}
					}
					if(flag)
						break;
				}
			
			
				for(int j=3;j<6;++j)
				{
					bool flag = false;
					for(int k=3*i;k<3*i+3;++k)
					{
						if(grid[k][j]=='1')
						{
							grid[k][(j+1)%3+3] = '1';
							flag = true;
							break;
						}
					}
					if(flag)
						break;
				}
			
			
				for(int j=6;j<9;++j)
				{
					bool flag = false;
					for(int k=3*i;k<3*i+3;++k)
					{
						if(grid[k][j]=='1')
						{
							grid[k][(j+1)%3+6] = '1';
							flag = true;
							break;
						}
					}
					if(flag)
						break;
				}
			
		}

		for(int i=0;i<9;++i)
		{
			for(int j=0;j<9;++j)
			{
				cout << grid[i][j];
			}
			cout << endl;
		}


	}
	return 0;
}