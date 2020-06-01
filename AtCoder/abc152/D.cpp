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

int count(int a, int b)
{
	string s = to_string(a), t = to_string(b);
	if(s[0]==t[t.length()-1] && s[s.length()-1]==t[0])
	{
		return 1;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	if(n<10)
	{
		cout << n << endl;
	}
	else
	{
		ll h = n;
		n/=10;
		ll ans =  powl(n,2)+8LL;
		for(int i=n*10+1;i<=h;++i)
		{
			for(int j=1;j<=h;++j)
			{
				if(i!=j) ans+=2*count(i,j);
				else ans+=count(i,j);
			}
		}
		cout << ans << endl;

	}
	return 0;
}