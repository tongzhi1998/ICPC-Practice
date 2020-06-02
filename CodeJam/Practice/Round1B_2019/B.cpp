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

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int,int> mii;
typedef map<long long,long long> mll;
typedef set<int> si;
typedef set<long long> sll;

long long n,t,h;

int main()
{
	cin>>t;
	h=t;
	int r;
	while(t--)
	{
		vector<int> v(6);
		for(int i=0;i<6;++i)
		{
			cout << i+1 << endl;
			cin>>r;
			v[i] = r;
		}

		vector<int> diff;
		for(int i=1;i<6;++i)
		{
			diff.emplace_back(v[i]-v[i-1]);
		}

		vector<int> ans;
		for(int i=1;i<5;++i)
		{
			ans.emplace_back(diff[i]-2*diff[i-1]);
		}

		

		cout << "Case #" << h-t << ": " << ans << endl;
	}

	return 0;
}