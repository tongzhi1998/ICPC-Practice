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

long long n,t;

const int maxn = 110;

int ma[maxn][maxn];

int main()
{
	cin>>t;
	int h = t;
	while(t--)
	{
		cin>>n;
		memset(ma,0,sizeof(ma));
		int trace = 0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				cin>>ma[i][j];
				if(i==j)
				{
					trace+=ma[i][j];
				}
			}
		}

		int row = 0, col = 0;
		for(int i=0;i<n;++i)
		{
			set<int> s;
			s.clear();
			for(int j=0;j<n;++j)
			{
				if(s.find(ma[i][j])!=s.end())
				{
					row++;
					break;
				}
				s.insert(ma[i][j]);
			}
		}

		for(int j=0;j<n;++j)
		{
			set<int> s;
			s.clear();
			for(int i=0;i<n;++i)
			{
				if(s.find(ma[i][j])!=s.end())
				{
					col++;
					break;
				}
				s.insert(ma[i][j]);
			}
		}

		cout << "Case #" << h-t << ": " << trace << " " << row << " " << col << endl;
	}
	return 0;
}