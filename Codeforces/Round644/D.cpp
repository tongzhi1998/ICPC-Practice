/*
	Author: tongzhi1007
	Submission: 81216840
	Time: May/24/2020 16:56
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

vector<int> prime_fac(ll a)
{
	vector<int> ans;
	ans.emplace_back(1);
	for(int i=2;i<=sqrt(a);++i)
	{
		if(a%i==0)
		{
			ans.emplace_back(i);
			ans.emplace_back(a/i);
		}
	}
	ans.emplace_back(a);
	sort(ans.begin(),ans.end());
	return ans;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(k>=n)
		{
			cout << "1" << endl;
			continue;
		}
		vector<int> v = prime_fac(n);
		// debug;
		// for(int i=0;i<v.size();++i)
		// {
		// 	cout << v[i] << " ";
		// }
		// cout << endl;
		for(int i=v.size()-1;i>=0;--i)
		{
			if(v[i]<=k)
			{
				cout << n/v[i] << endl;
				break;
			}
		}
	}
	return 0;
}