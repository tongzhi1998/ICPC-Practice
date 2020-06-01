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


typedef long long ll;		
		
const int MOD = 1e9 + 7;		
const int N = 1e5 + 5;		
		
	
// inv[]: inverse element
int gcd(int a, int b)
{
  return b==0?a:gcd(b,a%b);
}

int lcm(int a, int b)
{
  return (a*b/gcd(a,b));
}

		
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

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}
	if(n==1)
	{
		cout << "1" << endl;
		return 0;
	}
	int divisor = gcd(v[0],v[1]);
	for(int i=2;i<n;++i)
	{
		divisor = gcd(divisor,v[i]);
	}
	for(int i=0;i<n;++i)
	{
		v[i]/=divisor;
	}
	vector<int> b(n);
	ll multi = 1;
	for(int i=0;i<n;++i)
	{
		multi*=v[i];
		multi%=MOD;
	}
	ll ans = 0;
	for(int i=0;i<n;++i)
	{
		ll curr = multi*powMod(v[i],MOD-2);
		curr%=MOD;
		ans+=curr;
	}

	cout << ans << endl;

	return 0;
}