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

ll num = 0;

const ll MOD = 998244353;

const int N = 5e5 + 5;

int f[N], inv[N], finv[N];

int powMod(int u, int v) {		
int res = 1;		
while (v) {		
if (v & 1) res = (ll)res * u % MOD;		
v >>= 1;		
u = (ll) u * u % MOD;		
}		
return res;		
}		
		
void initInv() {		
f[0] = 1;		
for (int i = 1; i < N; i++) {		
f[i] = (ll)f[i - 1] * i % MOD;		
}		
inv[0] = inv[1] = 1;		
for (int i = 2; i < N; i++) {		
inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;		
}		
finv[0] = finv[1] = 1;		
for (int i = 2; i < N; i++) {		
finv[i] = ((ll)finv[i - 1] * inv[i]) % MOD;		
}		
}		
		
int C(int x, int y) {		
if (y < 0) return 0;		
return ((ll)f[x] * finv[y] % MOD) * finv[x - y] % MOD;		
}		
		
int Lucas(int u, int v) {		
if (v == 0) return 1;		
return (ll)C(u % MOD, v % MOD) * Lucas(u / MOD, v / MOD) % MOD;		
}		


int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	initInv();
	cin>>n>>k;
	if(k==1)
	{
		cout << n << endl;
		return 0;
	}
	if(k>n)
	{
		cout << "0" << endl;
		return 0;
	}
	//cout << count(10) << endl;
	ll ans = 0;
	for(int i=1;i<=n;++i)
	{
		if(n/i<k) break;
		ans+=Lucas(n/i-1,k-1);
		ans%=MOD;
	}

	cout << ans << endl;
	return 0;
}