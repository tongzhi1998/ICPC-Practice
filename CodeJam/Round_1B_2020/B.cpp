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

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int,int> mii;
typedef map<long long,long long> mll;
typedef set<int> si;
typedef set<long long> sll;

long long n,t,h,a,b;
string verdict;

const int A1 = 1e9-5;

const int A2 = 1e9-50;

const int zero = 0;

const int sz = 1e9;

ll dist(ll x, ll y, ll z, ll w)
{
	return sqrtl(powl(x-z,2)+powl(y-w,2));
}

int main()
{
	cin>>t;
	h=t;
	cin>>a>>b;
	while(t--)
	{
		if(a==A1)
		{
			for(int i=-5;i<=5;++i)
			{
				bool flag = false;
				for(int j=-5;j<=5;++j)
				{
					cout << i << " " << j << endl;
					cin>>verdict;
					if(verdict == "CENTER")
					{
						flag = true;
						break;
					}
				}
				if(flag)
				{
					break;
				}
			}
		}
		else if(a==A2)
		{
			ll hn = -1, hs = -1, hw = -1, he = -1;
			for(int i=0;i<=73;++i) // north
			{
				cout << zero << " " << sz-i << endl;
				cin>>verdict;
				if(verdict=="HIT")
				{
					hn = i;
					break;
				}
			}
			for(int i=0;i<=73;++i) // south
			{
				cout << zero << " " << -sz+i << endl;
				cin>>verdict;
				if(verdict=="HIT")
				{
					hs = i;
					break;
				}
			}
			for(int i=0;i<=73;++i) // east
			{
				cout << sz-i << " " << zero << endl;
				cin>>verdict;
				if(verdict=="HIT")
				{
					he = i;
					break;
				}
			}
			for(int i=0;i<=73;++i) // west
			{
				cout << -sz+i << " " << zero << endl;
				cin>>verdict;
				if(verdict=="HIT")
				{
					hw = i;
					break;
				}
			}

			if(hn==50 && hs==50 && he==50 && hw == 50)
			{
				cout << zero << " " << zero << endl;
				cin>>verdict;
				continue;
			}
			if(hn!=-1) // northeast
			{
				if(he!=-1)
				{
					for(int i=-50;i<=50;++i)
					{
						bool flag = false;
						for(int j=-50;j<=50;++j)
						{
							if(dist(i,j,0,sz-hn)<=A2 && dist(i,j,0,sz-hn+1)>A2 && dist(i,j,sz-he,0)<=A2 && dist(i,j,sz-he+1,0)>A2)
							{
								cout << i << " " << j << endl;
								cin>>verdict;
								if(verdict!="CENTER")
									return -1;
								flag = true;
								break;
							}
						}
						if(flag)
						{
							break;
						}
					}
				}
				else
				{
					for(int i=-50;i<=50;++i)
					{
						bool flag = false;
						for(int j=-50;j<=50;++j)
						{
							if(dist(i,j,0,sz-hn)<=A2 && dist(i,j,0,sz-hn+1)>A2 && dist(i,j,-sz+hw,0)<=A2 && dist(i,j,-sz+hw-1,0)>A2)
							{
								cout << i << " " << j << endl;
								cin>>verdict;
								if(verdict!="CENTER")
									return -1;
								flag = true;
								break;
							}
						}
						if(flag)
						{
							break;
						}
					}
				}
			}
			else
			{
				if(he!=-1)
				{
					for(int i=-50;i<=50;++i)
					{
						bool flag = false;
						for(int j=-50;j<=50;++j)
						{
							if(dist(i,j,0,-sz+hs)<=A2 && dist(i,j,0,-sz+hs-1)>A2 && dist(i,j,sz-he,0)<=A2 && dist(i,j,sz-he+1,0)>A2)
							{
								cout << i << " " << j << endl;
								cin>>verdict;
								if(verdict!="CENTER")
									return -1;
								flag = true;
								break;
							}
						}
						if(flag)
						{
							break;
						}
					}
				}
				else
				{
					for(int i=-50;i<=50;++i)
					{
						bool flag = false;
						for(int j=-50;j<=50;++j)
						{
							if(dist(i,j,0,-sz+hs)<=A2 && dist(i,j,0,-sz+hs-1)>A2 && dist(i,j,-sz+hw,0)<=A2 && dist(i,j,-sz+hw-1,0)>A2)
							{
								cout << i << " " << j << endl;
								cin>>verdict;
								if(verdict!="CENTER")
									return -1;
								flag = true;
								break;
							}
						}
						if(flag)
						{
							break;
						}
					}
				}
			}


		}
	}

	return 0;
}