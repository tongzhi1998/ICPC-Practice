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

int n,m,t;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				if(i==n-1 && j==m-1)
				{
					cout << "W";
				}
				else
				{
					cout << "B";
				}
			}
			cout << endl;
		}
	}
	return 0;
}