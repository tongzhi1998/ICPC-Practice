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

string s;

int count(int a)
{
	string temp = to_string(a);
	int ans = 0;
	for(int i=0;i<temp.length();++i)
	{
		if(temp[i]!='0') ans++;
	}
	return ans;
}

int calc(int rem, int digit)
{
	if(rem>digit) return 0;
	if(rem==0) return 0;
	int ans = 1;
	int i=0;
	//cout << "rem is: " << rem << " digit is: " << digit << endl;
	while(i<rem)
	{
		ans*=(digit-i);
		i++;
	}
	int hold = rem;
	while(rem>0)
	{
		ans/=(rem--);
	}
	ans = ans*pow(9,hold);
	//cout << "ans is: " << ans << endl;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>s>>k;
	if(k>s.length())
	{
		cout << "0" << endl;
		return 0;
	}
	ll ans = 0;
	while(k>0)
	{
		int mx = stoi(s.substr(0,1));
		//cout << "mx is: " << mx << endl;
		if(s.length()==1)
		{
			ans+=s[0]-'0';
			break;
		}
		for(int i=0;i<mx;++i)
		{
			int cnt = count(i);
			if(cnt>k) continue;
			if(cnt==k) ans++;
			int rem = k-cnt;
			int digit = s.length()-1;
			ans+=calc(rem,digit);


		}

		int mx_cnt = count(mx);
		if(mx_cnt==k) ans++;
		s = s.substr(1);
		k-=mx_cnt;
	}

	cout << ans << endl;

	return 0;
}