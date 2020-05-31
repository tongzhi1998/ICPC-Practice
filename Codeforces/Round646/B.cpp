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

string s;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>s;
		n = s.length();

		int ans = INT_MAX;

		vector<int> cnt(n,0);
		cnt[0] = s[0]=='0' ? 0 : 1;
		for(int i=1;i<n;++i)
		{
			cnt[i] = cnt[i-1] + (s[i]=='1');
			//cout << i << " " << cnt[i] << endl;
		}
		for(int i=0;i<n;++i)
		{
			int cnt1 = (i+1)-cnt[i] + cnt[n-1]-cnt[i];
			int cnt2 = cnt[i] + n-i-1 - (cnt[n-1]-cnt[i]);
			//cout << i << " " << cnt1 << " " << cnt2 << endl;
			ans = min(ans,cnt1);
			ans = min(ans,cnt2);
		}
		cout << ans << endl;
		// int cnt1 = 0, cnt2 = 0, cnt = 0;
		// if(s[0]=='1') cnt2++;
		// else cnt1++;

		// int idx = -1;
		// for(int i=1;i<n;++i)
		// {
		// 	if(s[i]!='1')
		// 	{
		// 		idx = i;
		// 		break;
		// 	}
		// }
		// if(idx!=-1)
		// {
		// 	for(int i=idx;i<n;++i)
		// 	{
		// 		if(s[i]!='0') cnt++;
		// 	}
		// }

		// idx = -1;
		// for(int i=1;i<n;++i)
		// {
		// 	if(s[i]!='0')
		// 	{
		// 		idx = i;
		// 		break;
		// 	}
		// }

		// if(idx!=-1)
		// {
		// 	for(int i=idx;i<n;++i)
		// 	{
		// 		if(s[i]!='1') cnt2++;
		// 	}
		// }

		// cout << min(cnt1,cnt2) << endl;
	}
	return 0;
}