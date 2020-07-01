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

int n,a,b;


typedef long long ll;		
		
const int MOD = 1e9 + 7;					
		
int powMod(int u, int v) 
{		
	int res = 1;		
	while (v) 
	{		
		if (v & 1) res = (ll)res * u % MOD;		
		v >>= 1;		
		u = (ll) u * u % MOD;		
	}		
	return res;		
}		
	
int C(int x, int y)
{		
	if (y < 0) return 0;		
	ll ans = 1;
	for(int i=x;i>x-y;--i)
	{
		ans*=i;
		ans%=MOD;
	}
	ll div = 1;
	for(int i=1;i<=y;++i)
	{
		div*=i;
		div%=MOD;
	}
	div = powMod(div,MOD-2);
	ans*=div;
	ans%=MOD;
	return ans;
}		
		

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>a>>b;
	int minus = C(n,a)+C(n,b)+1;
	minus%=MOD;
	cout << (powMod(2,n)+MOD-minus)%MOD << endl;
	return 0;
}