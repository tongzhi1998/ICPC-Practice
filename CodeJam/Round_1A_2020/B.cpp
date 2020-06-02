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

vector<int> pow_2(int a)
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
		cin>>n;
		vector<pair<int,int>> ans; ans.clear();
		int offset = 0;
		if(n<=35)
		{
			for(int i=1;i<=n;++i)
			{
				ans.emplace_back(make_pair(i,i));
			}
		}
		else
		{
			n-=30;
			offset+=30;
			bool even = false;
			if((n&1)==0)
			{
				even = true;
				n--;
			}

			vector<int> v = pow_2(n);
			ll sum = 0;
			ans.emplace_back(make_pair(1,1));
			int last = 0; // 0 indicates left and 1 indicates right
			for(int i=1;i<v.size();++i)
			{
				if(v[i]==0)
				{
					offset--;
					if(last==0)
					{
						ans.emplace_back(i+1,1);
					}
					else
					{
						ans.emplace_back(i+1,i+1);
					}
				}
				else // v[i] = 1
				{
					if(last==0)
					{
						for(int j=0;j<i+1;++j)
						{
							ans.emplace_back(i+1,j+1);
						}
						last = 1;
					}
					else
					{
						for(int j=i;j>=0;--j)
						{
							ans.emplace_back(i+1,j+1);
						}
						last = 0;
					}
				}
			}
			if(last==0)
			{
				for(int i=1;i<=offset;++i)
				{
					ans.emplace_back(v.size()+i,1);
				}
				if(even)
				{
					ans.emplace_back(v.size()+offset+1,1);
				}
			}
			else
			{
				for(int i=1;i<=offset;++i)
				{
					ans.emplace_back(v.size()+i,v.size()+i);
				}
				if(even)
				{
					ans.emplace_back(v.size()+offset+1,v.size()+offset+1);
				}
			}
		}


		
		cout << "Case #" << h-t << ": " << endl;
		for(int i=0;i<ans.size();++i)
		{
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}

	return 0;
}