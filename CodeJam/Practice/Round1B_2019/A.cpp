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

long long n,t,p,q;

bool cmp(pair<int,int>&a, pair<int,int>& b)
{
	return a.second < b.second;
}

int main()
{
	cin>>t;
	int h=t;
	while(t--)
	{
		cin>>p>>q;
		vector<int> north, south, east, west;
		
		for(int i=0;i<p;++i)
		{
			int a, b;
			char d;
			cin>>a>>b>>d;
			if(d=='N')
			{
				north.emplace_back(b);
			}
			else if(d=='S')
			{
				south.emplace_back(b);
			}
			else if(d=='E')
			{
				east.emplace_back(a);
			}
			else
			{
				west.emplace_back(a);
			}
		}
		sort(north.begin(),north.end());
		sort(south.begin(),south.end());
		sort(east.begin(),east.end());
		sort(west.begin(),west.end());

		int d1 = south.size(), p1 = 0, d2 = west.size(), p2 = 0;
		for(int i=0;i<north.size();++i)
		{
			int pos = north[i];
			int cnt = 0;
			for(int j=0;j<i;++j)
			{
				if(north[j]<north[i])
				{
					cnt++;
				}
				else
				{
					break;
				}
			}
			for(int j=0;j<south.size();++j)
			{
				if(south[j]>north[i])
				{
					cnt++;
				}
			}
			if(cnt>d1)
			{
				d1 = cnt;
				p1 = north[i];
			}

			pos = north[i]+1;
			cnt = i+1;
			for(int j=0;j<south.size();++j)
			{
				if(south[j]>north[i]+1)
				{
					cnt++;
				}
			}
			if(cnt>d1)
			{
				d1 = cnt;
				p1 = north[i]+1;
			}
		

		}

		for(int i=0;i<east.size();++i)
		{
			int pos = east[i];
			int cnt = 0;
			for(int j=0;j<i;++j)
			{
				if(east[j]<east[i])
				{
					cnt++;
				}
				else
				{
					break;
				}
			}
			for(int j=0;j<west.size();++j)
			{
				if(west[j]>east[i])
				{
					cnt++;
				}
			}
			if(cnt>d2)
			{
				d2 = cnt;
				p2 = east[i];
			}

			pos = east[i]+1;
			cnt = i+1;
			for(int j=0;j<west.size();++j)
			{
				if(west[j]>east[i]+1)
				{
					cnt++;
				}
			}
			if(cnt>d2)
			{
				d2 = cnt;
				p2 = east[i]+1;
			}
		

		}
		cout << "Case #" << h-t << ": " << p2 << " " << p1 << endl;
	}

	return 0;
}