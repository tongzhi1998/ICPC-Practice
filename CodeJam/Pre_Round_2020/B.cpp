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

long long t;

int main()
{
	cin>>t;
	int h = t;
	while(t--)
	{
		string s;
		cin>>s;
		int n = s.length();
		string ans; ans.clear();
		int curr = 0;
		for(int i=0;i<n;++i)
		{
			if(curr==s[i]-'0')
			{
				ans+=s[i];
			}
			else if(s[i]-'0'>curr)
			{
				for(int j=0;j<(s[i]-'0')-curr;++j)
				{
					ans+='(';
				}
				ans+=s[i];
				curr = s[i]-'0';
			}
			else
			{
				for(int j=0;j<curr-(s[i]-'0');++j)
				{
					ans+=')';
				}
				ans+=s[i];
				curr = s[i]-'0';
			}
		}
		for(int i=0;i<s[n-1]-'0';++i)
		{
			ans+=')';
		}
		cout << "Case #" << h-t << ": " << ans << endl;
	}
	return 0;
}