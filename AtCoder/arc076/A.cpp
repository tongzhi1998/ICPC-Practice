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

long long n,k,m;

const int mod = 1e9+7;

ll perm(ll n)
{
	ll ans = 1;
	while(n)
	{
		ans*=n;
		ans%=mod;
		n--;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	ll ans = 1;
	if(m>n) swap(m,n);
	if(n-m>1)
	{
		cout << "0" << endl;
		return 0;
	}
	if(n==m)
	{
		ans*=perm(n);
		ans%=mod;
		ans*=perm(m);
		ans%=mod;
		ans*=2;
		ans%=mod;
	}
	else
	{
		ans*=perm(n);
		ans%=mod;
		ans*=perm(m);
		ans%=mod;
	}
	cout << ans << endl;
	return 0;
}