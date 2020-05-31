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

ll n,m,L,R;

const int mod = 998244353;

int fastExp(long long base, long long p, int mod){
	if(p == 0) return 1;
	else if(p == 1) return base%mod;
	else{
		long long res = fastExp(base, p/2, mod)%mod;
		res *= res;
		res %= mod;
		if(p%2 == 1){res *= base; res %= mod;} 
		return res;
	}
}

int main()
{
	cin>>n>>m>>L>>R;
	if(L==R)
	{
		cout << "1" << endl;
		return 0;
	}
	ll ans = 1;
	if()
	return 0;
}