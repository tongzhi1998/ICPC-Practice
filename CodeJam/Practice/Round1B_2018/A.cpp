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

long long n,t,h,l;

vector<int> calc()
{
	vector<int> ans;
	for(int i=1;i<=n;++i)
	{
		double d = 100*i/(double)n;
		if(d-floor(d)>=0.5) ans.emplace_back(i);
	}
	return ans;
}

int main()
{
	cin>>t;
	h = t;
	while(t--)
	{
		cin>>n>>l;
		vector<int> v(l);
		int curr = 0;
		for(int i=0;i<l;++i)
		{
			cin>>v[i];
			curr+=v[i];
		}
		int rem = n-curr;
		vector<int> tar = calc();

		// debug;
		// for(int i=0;i<tar.size();++i)
		// {
		// 	cout << tar[i] << " ";
		// }
		// cout << endl;
		int ans = 0;
		vector<int> required;
		for(int i=0;i<l;++i)
		{
			if(v[i]*100/(double)(n)-v[i]*100/n>=0.5){
				ans+=ceil(v[i]*100/(double)n);
				continue;
			} 
			auto it = lower_bound(tar.begin(),tar.end(),v[i]);
			ans+=v[i]*100/n;
			if(it==tar.end()) continue;
			int diff = *it-v[i];
			//cout << "diff is: " << diff << endl;
			required.emplace_back(diff);
		}
		sort(required.begin(),required.end());
		int extra = 0;
		if(tar.size()!=0)
			extra = tar[0];
		//cout << "ans is: " << ans << endl;
		for(int i=0;i<required.size();++i)
		{
			if(required[i]<extra)
			{
				rem-=required[i];
				if(rem<0) {
					rem+=required[i]; 
					break;
				}
				ans++;
				//cout << "ans is now: " << ans << endl;
				ans+=((100*required[i])/n);
				//cout << "ans is now: " << ans << endl;
			}
			else
			{
				break;
			}

		}
		if(extra!=0)ans+=max(rem,0)/extra;
		ans+=max(rem,0)*(100/n);
		cout << "Case #" << h-t << ": " << ans << endl;
	}
	return 0;
}