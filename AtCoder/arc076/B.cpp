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

const int maxn = 1e5+10;

int a,b;

struct Node{
	int x;
	int y;
	int idx;
};

int fa[maxn];

int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;
    fa[x]=y;
}

bool cmp(vector<int>& A, vector<int>& B)
{
	return A[0]<B[0];
}

bool cmp_x(Node& A, Node& B)
{
	return A.x<B.x;
}

bool cmp_y(Node& A, Node& B)
{
	return A.y < B.y;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		fa[i] = i;
	}
	vector<Node> node_x;
	vector<Node> node_y;
	for(int i=0;i<n;++i)
	{
		cin>>a>>b;
		Node temp{a,b,i};
		node_x.emplace_back(temp);
		node_y.emplace_back(temp);
	}

	sort(node_x.begin(),node_x.end(),cmp_x);
	sort(node_y.begin(),node_y.end(),cmp_y);

	vector<vector<int>> diff_x, diff_y;

	for(int i=1;i<n;++i)
	{
		diff_x.emplace_back(vector<int>{node_x[i].x-node_x[i-1].x,node_x[i].idx,node_x[i-1].idx});
		diff_y.emplace_back(vector<int>{node_y[i].y-node_y[i-1].y,node_y[i].idx,node_y[i-1].idx});
	}

	sort(diff_x.begin(),diff_x.end(),cmp);
	sort(diff_y.begin(),diff_y.end(),cmp);

	ll ans = 0, cnt = 0;

	int ptr1 = 0, ptr2 = 0;
	while(cnt!=n-1)
	{
		if(diff_x[ptr1][0]<=diff_y[ptr2][0])
		{
			int a = diff_x[ptr1][1], b = diff_x[ptr1][2];
			if(find(a)==find(b)) ptr1++;
			else
			{
				ans+=diff_x[ptr1][0];
				unite(a,b);
				cnt++;
			}
		}
		else
		{
			int a = diff_y[ptr2][1], b = diff_y[ptr2][2];
			if(find(a)==find(b)) ptr2++;
			else
			{
				ans+=diff_y[ptr2][0];
				unite(a,b);
				cnt++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}