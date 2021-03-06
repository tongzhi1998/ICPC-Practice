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

ll n,m;

int main()
{
	cin>>n>>m;
	vector<ll> v(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}
	if(n>m)
	{
		cout << "0" << endl;
	}
	else
	{
		vector<int> all;
		ll ans = 1;
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				ans*=abs(v[i]-v[j]);
				ans%=m;
			}
		}
		cout << ans << endl;
	}
	return 0;
}