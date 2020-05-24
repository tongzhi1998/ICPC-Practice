/*
	Author: tongzhi1007
	Submission: 81216840
	Time: May/24/2020 16:47
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

long long n,k,t;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;++i)
		{
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		bool diff = false;
		int odd = 0;
		for(int i=0;i<v.size();++i)
		{
			if(v[i]%2==1) odd++;
			if(i!=v.size()-1)
			{
				if(v[i+1]-v[i]==1)
					diff = true;
			}
		}
		if(diff || odd%2==0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}