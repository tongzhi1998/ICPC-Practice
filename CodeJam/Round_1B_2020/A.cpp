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

long long n,t,h,x,y;

vector<int> binary(int a)
{
	vector<int> ans;
	while(a!=0)
	{
		ans.emplace_back(a%2);
		a/=2;
	}
	return ans;
}

int main()
{
	cin>>t;
	h=t;
	while(t--)
	{
		cin>>x>>y;
		bool f1 = false, f2 = false, flag = false;
		if(x<0) f1 = true;
		if(y<0) f2 = true;
		x = abs(x), y = abs(y);
		vector<int> v1 = binary(x);
		vector<int> v2 = binary(y);
		ll add = x+y;
		vector<int> v3 = binary(add);
		
		vector<char> ans; ans.clear();
		if(v3[0]==0)
		{
			flag = true;
		}
		else
		{
			for(int i=0;i<(int)v3.size()-1;++i)
			{
				if(v3[i]==1 && v3[i+1]!=0)
				{
					if(i<v1.size() && v1[i]==1)
					{
						ans.emplace_back('E');
					}
					else
					{
						ans.emplace_back('N');
					}
				}
				else
				{
					v3[i+1] = 1;
					if(i<v1.size() && v1[i]==1)
					{
						ans.emplace_back('W');
						x+=powl(2,i);
						v1 = binary(x);
					}
					else
					{
						ans.emplace_back('S');
						y+=powl(2,i);
						v2 = binary(y);
					}
				}
			}
			if(v1.size()==v3.size()) ans.emplace_back('E');
			else ans.emplace_back('N');
		}
		if(flag)
		{
			cout << "Case #" << h-t << ": IMPOSSIBLE" << endl;
		}
		else
		{
			cout << "Case #" << h-t << ": ";
			if(f2)
			{
				for(int i=0;i<ans.size();++i)
				{
					if(ans[i]=='N') ans[i] = 'S';
					else if(ans[i]=='S') ans[i] = 'N';
				}
			}
			if(f1)
			{
				for(int i=0;i<ans.size();++i)
				{
					if(ans[i]=='W') ans[i] = 'E';
					else if(ans[i]=='E') ans[i] = 'W';
				}
			}
			for(int i=0;i<ans.size();++i)
			{
				cout << ans[i];
			}
			cout << endl;
		}
	}

	return 0;
}