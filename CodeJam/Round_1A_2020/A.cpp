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

long long h,n,t;

const int maxn = 55;

vector<string> v[maxn];
vector<string> con;

bool cmp(const string& a, const string& b)
{
	return a.length()<b.length() || (a.length()==b.length() && a<b);
}

int main()
{
	cin>>t;
	h=t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;++i)
		{
			v[i].clear();
			string s;
			cin>>s;
			string temp="";
			for(int j=0;j<s.length();++j)
			{
				if(s[j]!='*')
				{
					temp+=s[j];
				}
				else
				{
					v[i].emplace_back(temp);
					temp = "";
				}
			}
			v[i].emplace_back(temp);
		}
		vector<string> prefix, suffix;
		for(int i=0;i<n;++i)
		{
			prefix.emplace_back(v[i][0]);
			suffix.emplace_back(v[i][v[i].size()-1]);
		}

		sort(prefix.begin(),prefix.end(),cmp);
		sort(suffix.begin(),suffix.end(),cmp);
		bool flag = false;
		for(int i=0;i<n-1;++i)
		{
			if(prefix[i]=="") continue;
			for(int j=0;j<prefix[i].length();++j)
			{
				if(prefix[i][j]!=prefix[i+1][j])
				{
					flag = true;
					break;
				}
			}
			if(flag)
				break;
		}

		for(int i=0;i<n-1;++i)
		{
			if(suffix[i]=="") continue;
			for(int j=suffix[i].length()-1;j>=0;--j)
			{
				if(suffix[i][j]!=suffix[i+1][j+suffix[i+1].length()-suffix[i].length()])
				{
					flag = true;
					break;
				}
			}
			if(flag)
				break;
		}

		if(flag){
			cout << "Case #" << h-t << ": " << "*" << endl;
		}
		else
		{
			string ans = prefix[n-1];
			for(int i=0;i<n;++i)
			{
				for(int j=1;j<v[i].size()-1;++j)
				{
					ans+=v[i][j];
				}
			}
			ans+=suffix[n-1];
			cout << "Case #" << h-t << ": " << ans << endl;
		}
	}

	return 0;
}