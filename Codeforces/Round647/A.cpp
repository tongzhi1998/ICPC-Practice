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

long long n,k,t,a,b;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a==b)
		{
			cout << "0" << endl;
		}
		else if(a>b)
		{
			ll diff = a/b;
			if(a%b!=0)
			{
				cout << "-1" << endl;
				continue;
			}
			bool flag = false;
			for(ll i=0;i<=100;++i)
			{
				if(powl(2,i)==diff)
				{
					flag = true;
					cout << (i+2)/3 << endl;
					break;
				}
			}
			if(!flag)
			{
				cout << "-1" << endl;
			}
		}
		else
		{
			swap(a,b);
			ll diff = a/b;
			if(a%b!=0)
			{
				cout << "-1" << endl;
				continue;
			}
			bool flag = false;
			for(ll i=0;i<=100;++i)
			{
				if(powl(2,i)==diff)
				{
					flag = true;
					cout << (i+2)/3 << endl;
					break;
				}
			}
			if(!flag)
			{
				cout << "-1" << endl;
			}
		}
	}
	return 0;
}