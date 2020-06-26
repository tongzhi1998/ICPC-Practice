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

int n,k,t;

string s;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>s;
		n = s.length();
		vector<int> v(n);
		int curr = 0;
		for(int i=0;i<n;++i)
		{
			if(s[i]=='+') curr++;
			else curr--;
			v[i] = curr;
		}
		ll ans = 0;
		int mn = 0;
		for(int i=0;i<n;++i)
		{
			if(v[i]<mn)
			{
				ans+=(i+1);
				mn = v[i];
			}
		}
		ans+=n;
		cout << ans << endl;
	}
	return 0;
}