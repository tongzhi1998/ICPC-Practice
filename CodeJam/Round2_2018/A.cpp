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

long long n,t,h,c;

int main()
{
	cin>>t;
	h = t;
	while(t--)
	{
		cin>>c;
		vector<int> v(c);
		for(int i=0;i<c;++i)
		{
			cin>>v[i];
		}
		
		if(v[0]==0 || v[c-1]==0)
		{
			cout << "Case #" << h-t << ": " <<"IMPOSSIBLE" << endl;
			continue;
		}
		
		int 
	}
	return 0;
}