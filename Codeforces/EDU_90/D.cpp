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
		cin>>n;
		vector<int> v(n);
		ll curr = 0;
		for(int i=0;i<n;++i)
		{
			cin>>v[i];
			if(i%2==0) curr+=v[i];
		}
		vector<int> even, odd;
		for(int i=0;i<n-1;i+=2)
		{
			even.emplace_back(v[i+1]-v[i]);
		}

		for(int i=1;i<n-1;i+=2)
		{
			odd.emplace_back(v[i]-v[i+1]);
		}

		ll extra = 0;
		ll accum = 0;
		for(int i=0;i<even.size();++i)
		{
			accum+=even[i];
			if(accum<0) accum = 0;
			extra = max(extra,accum);
		}
		//cout << "extra is: " << extra << endl;
		accum = 0;
		for(int i=0;i<odd.size();++i)
		{
			accum+=odd[i];
			if(accum<0) accum = 0;
			extra = max(extra,accum);
		}
		//cout << curr << " " << extra << endl;
		ll ans = curr+extra;

		cout << ans << endl;


	}
	return 0;
}