/*
	Author: day_dream
	Submission: 80178131
	Time: May/15/2020 01:30	
*/


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

const int maxn = 5e5+10;

ll dp[maxn];

int main()
{
	dp[1] = 0;
	for(ll i=3;i<=maxn;i+=2)
	{
		dp[i] = dp[i-2] + (powl(i,2)-powl(i-2,2))*(i/2);
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout << dp[n] << endl;
	}
	return 0;
}