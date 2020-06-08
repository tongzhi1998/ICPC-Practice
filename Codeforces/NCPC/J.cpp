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

long long a,b,c,d;

int main()
{
	cin>>a>>b>>c>>d;
	ll d_a = a*2;
	ll numZ, numO;
	if(a==0 && b==0 && c==0 && d==0){
		cout << "0" << endl;
		return 0;
	}
	if(a==0 && d==0)
	{
		if(b==1 && c==0)
		{
			cout << "01" << endl;
		}
		else if(c==1 && b==0)
		{
			cout << "10" << endl;
		}
		else
		{
			cout << "impossible" << endl;
		}
		return 0;
	}
	if(a==0)
	{
		if(!(b==0 && c==0))
		{
			numZ = 1;
		}
		else
		{
			numZ = 0;
		}
		numO = sqrt(d*2)+1;
	}
	else if(d==0)
	{
		if(!(b==0 && c==0))
		{
			numO = 1;
		}
		else
		{
			numO = 0;
		}
		numZ = sqrt(a*2)+1;
	}
	else
	{
		numZ = sqrt(a*2)+1;
		numO = sqrt(d*2)+1;
	}
	if(numZ*(numZ-1)!=a*2)
	{
		cout << "impossible" << endl;
		return 0;
	}
	if(numO*(numO-1)!=d*2)
	{
		cout << "impossible" << endl;
		return 0;
	}

	ll total = numO+numZ;

	if(total*(total-1)!=2LL*(a+b+c+d))
	{
		cout << "impossible" << endl;
		return 0;
	}
	vector<int> one;
	ll cntZ = numZ;
	for(int i=0;i<total;++i)
	{
		if(cntZ<=c)
		{
			c-=cntZ;
			one.emplace_back(i);
			if(c==0) break;
		}
		else
		{
			cntZ--;
		}
	}
	vector<char> ans(total,'0');
	int pos = total-1;
	while(one.size()<numO)
	{
		one.emplace_back(pos--);
	}
	for(int i=0;i<one.size();++i)
	{
		ans[one[i]] = '1';
	}
	for(int i=0;i<total;++i)
	{
		cout << ans[i];
	}
	cout << endl;
	return 0;
}