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

long long h,n,t,r,c;

const int maxr = 110;

int grid[maxr][maxr];

int temp[maxr][maxr];

int main()
{
	cin>>t;
	h=t;
	while(t--)
	{
		cin>>r>>c;
		for(int i=0;i<r;++i)
		{
			for(int j=0;j<c;++j)
			{
				cin>>grid[i][j];
				temp[i][j] = grid[i][j];
			}
		}
		int num = r*c;
		int numBF = num+1;
		ll ans = 0;
		
		cout << "Case #" << h-t << ": " << ans << endl;
	}
	return 0;
}