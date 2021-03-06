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

int main()
{

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	ll sum = 0;
	ll mx = 0;
	vector<ll> v(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}
	for(int i=0;i<k;++i)
	{
		sum+=v[i];
	}

	mx = sum;
	for(int i=k;i<n;++i)
	{
		sum-=v[i-k];
		sum+=v[i];
		mx = max(sum,mx);
	}
	cout << setprecision(10) << fixed << (mx+k)/(double)2 << endl;
	return 0;
}