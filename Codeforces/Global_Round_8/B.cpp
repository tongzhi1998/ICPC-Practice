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

const string st = "codeforces";

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>k;
	ll cnt = 1;
	ll s = 1;
	ll ans = 1;
	while(ans<k)
	{
		cnt++;
		ans = powl(cnt,10LL);
	}
	vector<ll> v(10);
	for(int i=0;i<10;++i)
	{
		v[i] = cnt-1;
	}
	for(ll i=0;i<10;++i)
	{
		ll ans = 1;
		for(int j=0;j<10;++j)
		{
			ans*=v[j];
		}
		if(ans>=k) break;
		v[i]++;
	}
	string res = "";
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<v[i];++j)
		{
			res+=st[i];
		}
	}
	cout << res << endl;
	return 0;
}