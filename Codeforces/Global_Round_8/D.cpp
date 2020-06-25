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

vector<int> cnt(21,0);

void count(int a)
{
	vector<int> digit;
	while(a!=0)
	{
		digit.emplace_back(a%2);
		a/=2;
	}
	for(int i=0;i<digit.size();++i)
	{
		cnt[20-i]+=digit[i];
		//cout << digit[i] << " ";
	}
	//cout << endl;


}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}
	
	for(int i=0;i<n;++i)
	{
		count(v[i]);
	}
	ll ans = 0;
	for(int i=0;i<21;++i)
	{
		int curr = 0;
		while(cnt[i]>0)
		{
			curr = 0;
			cnt[i]--;
			curr+=pow(2,20-i);
			for(int j=i+1;j<21;++j)
			{
				if(cnt[j]>0){
					cnt[j]--;
					curr+=pow(2,20-j);
				}
			}
			ans+=pow(curr,2);
		}
	}
	cout << ans << endl;
	return 0;
}