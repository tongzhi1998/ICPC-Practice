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

long long k;

int main()
{
	cin>>k;
	cout << "2 3" << endl;
	if(k==0)
	{
		cout << "0 0 0" << endl;
		cout << "0 0 0" << endl;
		return 0;
	}
	int cnt = 0;
	int h = k;
	while(h!=0)
	{
		h/=2;
		cnt++;
	}
	int num = pow(2,cnt);
	cout << num+k << " " << k << " 0" << endl;
	cout << num << " " << num+k << " " << k << endl;
	return 0;
}