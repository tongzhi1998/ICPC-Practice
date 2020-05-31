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

const int maxn = 1010;

vector<int> d[maxn];

int main()
{
	for(int i=1;i<=maxn;++i)
	{
		for(int j=i;j<=maxn;j+=i)
		{
			d[j].emplace_back(i);
		}
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> v(n);
		vector<int> c(n);
		for(int i=0;i<n;++i)
		{
			cin>>v[i];
		}
		unordered_set<int> s;
		for(int i=0;i<n;++i)
		{
			if(v[i]%2==0)
			{
				c[i] = 1;
				s.insert(1);
			}
			else if(v[i]%3==0)
			{
				c[i] = 2;
				s.insert(2);
			}
			else if(v[i]%5==0)
			{
				c[i] = 3;
				s.insert(3);
			}
			else if(v[i]%7==0)
			{
				c[i] = 4;
				s.insert(4);
			}
			else if(v[i]%11==0)
			{
				c[i] = 5;
				s.insert(5);
			}
			else if(v[i]%13==0)
			{
				c[i] = 6;
				s.insert(6);
			}
			else if(v[i]%17==0)
			{
				c[i] = 7;
				s.insert(7);
			}
			else if(v[i]%19==0)
			{
				c[i] = 8;
				s.insert(8);
			}
			else if(v[i]%23==0)
			{
				c[i] = 9;
				s.insert(9);
			}
			else if(v[i]%29==0)
			{
				c[i] = 10;
				s.insert(10);
			}
			else if(v[i]%31==0)
			{
				c[i] = 11;
				s.insert(11);
			}
		}
		int m = s.size();
		map<int,int> mp;
		int cnt = 1;
		for(auto it: s)
		{
			mp.emplace(it,cnt++);
		}
		cout << m << endl;
		// for(int i=0;i<n;++i)
		// {
		// 	cout << v[i] << " ";
		// }
		// cout << endl;
		for(int i=0;i<n;++i)
		{
			cout << mp[c[i]] << " ";
		}
		cout << endl;
	}
	return 0;
}