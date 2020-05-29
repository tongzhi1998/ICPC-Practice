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
		vector<int> v(n);

		bool has = false;
		for(int i=0;i<n;++i)
		{
			cin>>v[i];
			if(v[i]==k) has = true;
		}
		if(n==1 && v[0]==k)
		{
			cout << "yes" << endl;
			continue;
		}
		if(!has)
		{
			cout << "no" << endl;
			continue;
		}
		bool valid = false;
		for(int i=0;i<n;++i)
		{
			if((i+1<n && v[i]>=k && v[i+1]>=k)||(i+2<n && v[i]>=k && v[i+2]>=k))
			{
				valid = true;
				break;
			}
		}
		if(valid)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}

	}

	return 0;
}