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

const int MAX = 502;
  const int inf = (int) 1e9;
  const int MAGIC = 100;
  vector< vector<int> > dp(MAX, vector<int>(MAX, -inf));

int calc1(int r, int b)
{
	int base1 = 1;
	int cnt1 = 2;
	vector<int> sum;
	sum.emplace_back(base1);
	while(base1<=600)
	{
		base1+=(cnt1++);
		sum.emplace_back(base1);
	}
		if(r<b) swap(r,b);
		if(b==0)
		{
			return upper_bound(sum.begin(),sum.end(),r)-sum.begin();
		}
		auto it = upper_bound(sum.begin(),sum.end(),b);
		int base = it-sum.begin();
		int hold = base;
		//cout << "base is: " << base << endl;
		base*=2;
		int val = *(it-1);
		r-=val;
		b-=val;
		int cnt = 1;
		while(b--)
		{
			r-=(cnt++);
			if(r<0) break;
			base++;
		}
		if(r>0)
		{
			while(r>hold)
			{
				r-=++hold;
				base++;
			}
		}

		return base;
}

void pre()
{
  dp[0][0] = 0;
  for (int x = 0; x <= MAGIC; x++) {
    for (int y = 0; y <= MAGIC; y++) {
      if (x + y == 0) {
        continue;
      }
      for (int i = 0; i < MAX-x; i++) {
        for (int j = 0; j < MAX-y; j++) {
          dp[i + x][j + y] = max(dp[i + x][j + y], dp[i][j] + 1);
        }
      }
    }
    cout << x << endl;
  }
}


int calc2(int r, int b) {
  return dp[r][b];
}

int main()
{
	pre();
	for(int r=0;r<50;++r)
	{
		for(int b=0;b<50;++b)
		{
			if(r+b==0) continue;
			//cout << r << " " << b << endl;
			int ans1 = calc1(r,b);
			//cout << ans1 << endl;
			int ans2 = calc2(r,b);
			//cout << r << b << endl;
			if(ans1!=ans2)
			{
				cout << "when r = " << r << " and b = " << b << endl;
				cout << "My answer: " << ans1 << endl;
				cout << "Right answer" << ans2 << endl;
				return 0;
			}
		}
	}
	return 0;
}
