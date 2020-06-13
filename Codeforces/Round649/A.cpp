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

long long n,k,t;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		vector<ll> v(n);
		ll sum = 0;
		for(int i=0;i<n;++i)
		{
			cin>>v[i];
			sum+=v[i];
		}
		int front = 0, end = n-1;
		ll ans = end-front+1;
		if(sum%k!=0)
		{
			cout << n << endl;
			continue;
		}
		ans = -1;
		for(ll i=0;i<n;++i)
		{
			if(v[i]%k!=0)
			{
				ans = max(ans,max(i,n-i-1));
			}
		}
		cout << ans << endl;

	}
	return 0;
}