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

string to_binary(ll a)
{
	string ans;
	while(a!=0)
	{
		ans+=a%2+'0';
		a/=2;
	}
	while(ans.length()<63)
	{
		ans+='0';
	}
	reverse(ans.begin(),ans.end());
	//cout << a << " " << ans << endl;
	return ans;

}

int main()
{
	cin>>n>>k;
	vector<ll> v;
	for(int i=0;i<n;++i)
	{
		ll a;
		cin>>a;
		v.emplace_back(a);
	}

	vector<string> all;
	for(int i=0;i<n;++i)
	{
		ll sum = 0;
		for(int j=i;j<n;++j)
		{
			sum+=v[j];
			//cout << "sum is: " << sum << endl;
			all.emplace_back(to_binary(sum));
		}
	}

	string ans; ans.clear();
	ll cnt = 0;
	for(ll i=0;i<63;++i)
	{
		cnt = 0;
		sort(all.begin(),all.end(),[&i](string a, string b){
			return a[i]>b[i];
		});
		int idx = 0;
		for(int j=0;j<all.size();++j)
		{
			if(all[j][i]=='1') 
			{
				cnt++;
			}
			else 
				break;
		}
		if(cnt>=k)
		{
			ans+='1';
			all = {all.begin(), all.begin()+cnt};
		}
		else
		{
			ans+='0';
		}
	}

	ll res = 0;
	for(int i=ans.size()-1;i>=0;--i)
	{
		if(ans[i]=='1')
		{
			res+=powl(2,ans.size()-i-1);
		}
	}
	cout << res << endl;
	return 0;
}