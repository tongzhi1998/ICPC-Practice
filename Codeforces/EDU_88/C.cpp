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

long long n,k,t,T,h,c;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>T;
	while(T--)
	{
		cin>>h>>c>>t;
		double t2 = abs((h+c)/(double)2 - t);
		int k = floor((h-t)/(double)(t*2-h-c));
		int k1 = k+1;
		double t1 = inf;
		double temp1 = abs((h*(k+1)+c*k)/(double)(2*k+1)-t);
		double temp2 = abs((h*(k1+1)+c*k1)/(double)(2*k1+1)-t);
		if(k>=0)
		{
			//double temp1 = abs((h*(k+1)+c*t)/(double)(2*k+1)-t);
			t1 = min(t1, abs((h*(k+1)+c*k)/(double)(2*k+1)-t));
		}
		if(k1>=0)
		{
			t1 = min(t1, abs((h*(k1+1)+c*k1)/(double)(2*k1+1)-t));
		}
		if(t2<t1)
		{
			cout << "2" << endl;
		}
		else if(t1<t2)
		{
			if(t1==temp1)
			{
				cout << 2*k+1 << endl;
			}
			else
			{
				cout << 2*k1+1 << endl;
			}
		}
		else
		{
			if(h==c)
			{
				cout << "1" << endl;
			}
			else
			{
				cout << "2" << endl;
			}
		}
	}
	return 0;
}