/*
	Author: tongzhi1007
	Submission: 81208973
	Time: May/24/2020 16:42
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
			cin>>v[i];
		sort(v.begin(),v.end());
		int diff = INT_MAX;
		for(int i=0;i<v.size()-1;++i)
		{
			diff = min(diff,v[i+1]-v[i]);
		}
		cout << diff << endl;
	}
	return 0;
}