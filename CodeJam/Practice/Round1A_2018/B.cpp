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

long long n,t,h,r,b,c;

const ll mx = 2e18+10;

ll ans = mx;


vector<vector<ll>> cashier;

void binary(ll l, ll rt)
{
	ll cnt = 0;
	ll mid = (l+rt)/2;
	if(rt<l)
		return;
	vector<ll> amount;
	for(ll i=0;i<c;++i)
	{
		vector<ll> cand = cashier[i];
		ll temp = min(cand[0],max(0LL,(mid-cand[2])/cand[1]));
		amount.emplace_back(temp);
	}
	sort(amount.begin(),amount.end(),std::greater<ll>());
	ll total = 0;
	for(ll i=0;i<r;++i)
	{
		total+=amount[i];
	}
	if(total<b)
	{
		binary(mid+1,rt);
	}
	else
	{
		ans = min(ans,mid);
		binary(l,mid-1);
	}
}

int main()
{
	cin>>t;
	h = t;
	while(t--)
	{
		cin>>r>>b>>c;
		cashier.resize(c);
		for(ll i=0;i<c;++i)
		{
			cashier[i].resize(3);
		}
		for(ll i=0;i<c;++i)
		{
			cin>>cashier[i][0]>>cashier[i][1]>>cashier[i][2];
		}
		ans = mx;
		binary(0,mx);
		cout << "Case #" << h-t << ": " << ans << endl;
	}
	return 0;
}