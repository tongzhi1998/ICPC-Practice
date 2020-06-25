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

long long n,k;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	int num = n+2;
	int k = 2*2+n*3;
	int lft = 0;
	cout << k << endl;
	for(int i=0;i<num;++i)
	{
		if(i==0)
		{
			cout << i << " " << i << endl;
			cout << i+1 << " " << i << endl;
		}
		else if(i==num-1)
		{
			cout << i-1 << " " << i << endl;
			cout << i << " " << i << endl;
		}
		else
		{
			for(int j=max(i-1,0);j<max(i-1,0)+3;++j)
			{
				cout << j << " " << i << endl;
			}
		}
	}
	return 0;
}