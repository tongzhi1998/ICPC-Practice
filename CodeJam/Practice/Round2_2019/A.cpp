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

int gcd(int a, int b)
{
  return b==0?a:gcd(b,a%b);
}

int lcm(int a, int b)
{
  return (a*b/gcd(a,b));
}

int _;

int main()
{
	cin >> _;

	set<pair<int,int>> cnt;
	vector<pair<int,int>> arr;
	for(int p = 1; p <= _; p++){
		int n;
		cin >> n;
		cnt.clear();
		arr.clear();
		for(int i = 0; i < n; i++){
			int x,y; cin >> x >> y;
			arr.emplace_back(x,y);
		}
		for(int i = 0; i < arr.size(); i++){
			for(int j = i + 1; j < arr.size(); j++){
				int a = arr[i].first;
				int b = arr[i].second;
				int c = arr[j].first;
				int d = arr[j].second;
				int nx = a - c;
				int ny = d - b;
				if(!nx || !ny || (nx > 0 && ny < 0) || (nx < 0 && ny > 0)) continue;
				nx = abs(nx); ny = abs(ny);
				int gcdt = gcd(nx,ny);
				cnt.insert(make_pair(nx/gcdt, ny/gcdt));
			}
		}
		int tpow = cnt.size();
		cout << "Case #" <<p << ": " << (1 << tpow) << endl;

	}
	return 0;
}



