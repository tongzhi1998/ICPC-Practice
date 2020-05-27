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

long long n,k,x;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	vector<ll> v(2*n);
	ll mx = 0;
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
		mx = max(mx,v[i]);
	}
	for(int i=n;i<2*n;++i)
	{
		v[i] = v[i-n];
	}
	ll ans = 0;
	if(k<=mx)
	{
		cout << ((2*mx-k+1)*k)/2 << endl;
		return 0;
	}
	ll base = 0, extra = 0, nxt = 1, val = 0;
	for(int i=1;i<=n;++i)
	{
		if(base!=0) {
			base-=v[i-1];
			val-=(v[i-1]*(v[i-1]+1))/2;
		}
		while(k-base>=v[i-1] && k-base>=v[nxt])
		{
			base+=v[nxt];
			val += (v[nxt]*(v[nxt]+1))/2;
			nxt++;
		}
		ll temp = min(k-base,v[i-1]-1);
		extra = ((v[i-1]+(v[i-1]-temp+1))*temp)/2;
		ans = max(ans,val+extra);
	}
	cout << ans << endl;
	return 0;
}