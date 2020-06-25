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

long long n,k,q;

string s,t,p;

int cnt[26];

int have[26];

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>q;
	while(q--)
	{
		memset(cnt,0,sizeof(cnt));
		memset(have,0,sizeof(have));
		cin>>s>>t>>p;
		int ptr2 = 0;
		int n = s.length(), m = t.length();
		if(n>m)
		{
			cout << "NO" << endl;
			continue;
		}
		bool ok = true;
		for(int i=0;i<n;++i)
		{
			if(ptr2==m)
			{
				ok = false;
				break;
			}
			while(t[ptr2]!=s[i])
			{
				if(ptr2==m-1)
				{
					ok = false;
					break;
				}
				ptr2++;
				cnt[t[ptr2-1]-'a']++;
			}
			ptr2++;
			if(!ok)
				break;
		}
		if(!ok)
		{
			//cout << "here1" << endl;
			cout << "NO" << endl;
			continue;
		}
		for(int i=ptr2;i<m;++i)
		{
			cnt[t[i]-'a']++;
		}

		for(int i=0;i<p.length();++i)
		{
			have[p[i]-'a']++;
		}

		// for(int i=0;i<26;++i)
		// {
		// 	cout << cnt[i] << " ";
		// }
		// cout << endl;

		// for(int i=0;i<26;++i)
		// {
		// 	cout << have[i] << " ";
		// }
		// cout << endl;

		for(int i=0;i<26;++i)
		{
			if(have[i]<cnt[i])
			{
				ok = false;
				break;
			}
		}

		if(!ok)
		{
			//cout << "here2" << endl;
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}


	}
	return 0;
}