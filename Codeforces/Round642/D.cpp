/*
	Author: day_dream
	Submission: 80178138
	Time: May/15/2020 01:30
*/


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

struct comp
{
	bool operator()(pair<int,int>&a, pair<int,int>&b)
	{
		return !(a.second-a.first>b.second-b.first || (a.second-a.first==b.second-b.first && a.first<b.first));
	}
};

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		//cout << "n is: " << n << endl;
		vector<int> v(n);
		priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
		int cnt = 1;
		pq.push(make_pair(0,n-1));
		while(!pq.empty())
		{
			pair<int,int> p = pq.top();
			pq.pop();
			//cout << p.first << " " << p.second << endl;
			if(p.first>p.second) continue;
			
			int mid = (p.first+p.second)/2;

			v[mid] = cnt++;
			
			pq.push(make_pair(p.first,mid-1));
			pq.push(make_pair(mid+1,p.second));
			
		}
		for(int i=0;i<n;++i)
		{
			cout << v[i] <<  " ";
		}
		cout << endl;
	}
	return 0;
}