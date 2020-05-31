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
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int num = n/k;
		vector<string> v(num);
		for(int i=0;i<num;++i)
		{
			string temp; temp.clear();
			for(int j=0;j<k;++j)
			{
				char c;
				cin>>c;
				temp+=c;
			}
			v[i] = temp;
		}
		int ans = 0;
		int occur[26];
		for(int i=0;i<26;++i)
		{
			occur[i] = 0;
		}
		if(k%2==0)
		{
			for(int i=0;i<k/2;++i)
			{
				for(int j=0;j<num;++j)
				{
					occur[v[j][i]-'a']++;
					occur[v[j][k-i-1]-'a']++;
				}
				int mx = 0;
				for(int j=0;j<26;++j)
				{
					mx = max(mx,occur[j]);
				}
				ans+=2*num-mx;
				for(int j=0;j<26;++j)
				{
					occur[j] = 0;
				}
			}
		}
		else
		{
			for(int i=0;i<k/2;++i)
			{
				for(int j=0;j<num;++j)
				{
					occur[v[j][i]-'a']++;
					occur[v[j][k-i-1]-'a']++;
				}
				int mx = 0;
				for(int j=0;j<26;++j)
				{
					mx = max(mx,occur[j]);
				}
				ans+=2*num-mx;
				for(int j=0;j<26;++j)
				{
					occur[j] = 0;
				}
			}
			for(int j=0;j<num;++j)
			{
				occur[v[j][k/2]-'a']++;
			}
			int mx = 0;
			for(int j=0;j<26;++j)
			{
				mx = max(mx,occur[j]);
			}
			ans+=num-mx;
			for(int j=0;j<26;++j)
			{
				occur[j] = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 