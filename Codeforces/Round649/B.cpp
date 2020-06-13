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

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;++i)
		{
			cin>>v[i];
		}
		int prev = v[0];
		vector<int> ans;
		ans.emplace_back(v[0]);
		for(int i=1;i<n;++i)
		{
			if(v[i]>prev)
			{
				if(i+1<n && v[i+1]>v[i]) continue;
				else 
				{
					prev = v[i];
					ans.emplace_back(prev);
				}
			}
			else
			{
				if(i+1<n && v[i+1]<v[i]) continue;
				else
				{
					prev = v[i];
					ans.emplace_back(prev);
				}
			}
		}
		cout << ans.size() << endl;
		for(int i=0;i<ans.size();++i)
		{
			cout << ans[i] <<  " ";
		}
		cout << endl;

	}
	return 0;
}