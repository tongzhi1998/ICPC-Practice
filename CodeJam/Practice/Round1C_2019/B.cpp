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

long long n,t,h;

char a;

vector<int> v[5];

int idx[5];

int main()
{
	cin>>t;
	h = t;
	while(t--)
	{
		string ans;
		for(int i=0;i<5;++i)
		{
			idx[i] = 0;
			v[i].clear();
		}
		for(int i=0;i<119;++i)
		{
			cout << i*5+1 << endl;
			cin>>a;
			v[a-'A'].emplace_back(i+1);

		}
		idx[0] = -1;
		for(int i=0;i<5;++i)
		{
			if(v[i].size()<24)
			{
				idx[0] = i;
				break;
			}
		}

		ans+=idx[0]+'A';
		for(int i=0;i<5;++i)
		{
			v[i].clear();
		}

		for(int i=0;i<23;++i)
		{
			int to = v[idx[0]][i];
			cout << to*5+2 << endl;
			cin>>a;
			v[a-'A'].emplace_back(i+1);

		}


		cout << "Case #" << h-t << ": " << ans << endl;
	}
	return 0;
}