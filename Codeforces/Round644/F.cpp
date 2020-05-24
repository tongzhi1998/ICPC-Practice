/*
	Author: tongzhi1007
	Submission: 81268437
	Time: May/24/2020 17:39
*/


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

long long n,k,t,m;

vector<string> v;

bool check(string& temp, int idx)
{
	for(int i=0;i<n;++i)
	{
		if(v[i][idx]!=temp[idx])
		{
			for(int j=idx+1;j<m;++j)
			{
				temp+=v[i][j];
			}
			break;
		}
	}
	//cout << "temp now is: " << temp << endl;
	for(int i=0;i<n;++i)
	{
		int cnt = 0;
		for(int j=0;j<m;++j)
		{
			if(temp[j]!=v[i][j]) cnt++;
		}
		if(cnt>=2) return false;
	}
	return true;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		v.resize(n);
		for(int i=0;i<n;++i)
		{
			cin>>v[i];
		}
		int idx = -1;
		sort(v.begin(),v.end());
		for(int i=0;i<m;++i)
		{
			for(int j=0;j<n-1;++j)
			{
				if(v[j][i]!=v[j+1][i])
				{
					idx = i;
					break;
				}
			}
			if(idx!=-1)
				break;
		}
		if(idx==-1)
		{
			cout << v[0] << endl;
			continue;
		}
		bool valid = false;
		string ans;
		for(int i=0;i<idx;++i)
		{
			ans+=v[0][i];
		}
		for(int i=0;i<n;++i)
		{
			string temp = ans;
			temp+=v[i][idx];
			//cout << "temp is: " << temp << endl;
			if(check(temp,idx))
			{
				valid = true;
				cout << temp << endl;
				break;
			}
		}

		if(!valid)
		{
			cout << "-1" << endl;
		}

	}
	return 0;
}