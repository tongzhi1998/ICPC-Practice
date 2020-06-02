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

long long n,t,l;

string ans;

set<string> s;

bool stop = false;


void allCombo(string curr, int pos, vector<vector<char>>& comb)
{
	if(stop) return;
	if(pos==l)
	{
		if(s.find(curr)==s.end())
		{
			ans = curr;
			stop = true;
		}
		return;
	}
	for(int i=0;i<comb[pos].size();++i)
	{
		string temp = curr+comb[pos][i];
		allCombo(temp,pos+1,comb);
	}

}

int main()
{
	cin>>t;
	ll h=t;
	while(t--)
	{
		stop = false;
		cin>>n>>l; 
		vector<string> words(n);
		s.clear();
		for(int i=0;i<n;++i)
		{
			cin>>words[i];
			s.insert(words[i]);
		}
		vector<set<char>> v(l);
		vector<vector<char>> comb(l);

		for(int i=0;i<l;++i)
		{
			for(int j=0;j<n;++j)
			{
				v[i].insert(words[j][i]);
			}
		}

		for(int i=0;i<l;++i)
		{
			for(auto it: v[i])
			{
				comb[i].emplace_back(it);
			}
		}

		ll num = 1;
		bool flag = false;
		for(int i=0;i<l;++i)
		{
			num*=(int)comb[i].size();
			if(num>n)
			{
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			cout << "Case #" << h-t << ": " << "-" << endl;
			continue;
		}
		string temp = "";
		allCombo(temp,0,comb);
		cout << "Case #" << h-t << ": " << ans << endl;
	}

	return 0;
}