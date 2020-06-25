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

const string A = "Alice";
const string B = "Bob";

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(k % 3 == 0) 
		{
			int mod = n % (k + 1);
			if( mod % 3 == 0 && mod != k)
			{
				cout << B << endl;
				continue;
			}
		} 
		else 
		{
			int mod = n % 3;
			if(mod == 0)
			{
				cout << B << endl;
				continue;
			}
		}
		
		cout << A << endl;
		
		
	}
	return 0;
}