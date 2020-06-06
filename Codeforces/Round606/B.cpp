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

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;

int t,n;

set<int> s;

int ans = 0;

void manip(int a)
{
	s.insert(a);
	while(a%2==0)
	{
		a/=2;
		s.insert(a);
		ans++;
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;

		s.clear();
		ans = 0;
		vector<int> v;
		for(int i=0;i<n;++i)
		{
			int a;
			cin>>a;
			if(a%2) continue;
			else
			{
				v.emplace_back(a);
			}
		}
		sort(v.begin(),v.end(),greater<int>());
		for(int i=0;i<v.size();++i)
		{
			if(s.find(v[i])==s.end())
			{
				manip(v[i]);
			}
		}
		cout << ans << endl;


	}
	return 0;
}