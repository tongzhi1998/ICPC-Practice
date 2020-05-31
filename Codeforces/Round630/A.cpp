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

int n,k,t,a,b,c,d;

int x,y,x1,y_,x2,y2;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d;
		cin>>x>>y;
		cin>>x1>>y_>>x2>>y2;
		if(x2-x1==0)
		{
			if(a!=0 || b!=0)
			{
				cout << "No" << endl;
				continue;
			}
		}
		if(y2-y_==0)
		{
			if(c!=0 || d!=0)
			{
				cout << "No" << endl;
				continue;
			}
		}
		if(x2-x<b-a)
		{
			cout << "No" << endl;
			continue;
		}
		if(x-x1<a-b)
		{
			cout << "No" << endl;
			continue;
		}
		if(y2-y<d-c)
		{
			cout << "No" << endl;
			continue;
		}
		if(y-y_<c-d)
		{
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;


	}
	return 0;
}

