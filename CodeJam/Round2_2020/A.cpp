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

long long n,t,l,r,h;

int main()
{
	cin>>t;
	h = t;
	while(t--)
	{
		cin>>l>>r;
		if(l>=r)
		{
			ll diff = l-r;
			ll root = sqrtl(1+8*diff);
			ll cnt = (root-1)/2;
			l-=(cnt*(cnt+1))/2;
			if(l-cnt-1>=r)
			{
				cnt++;
				l-=cnt;
			}
			ll k = 0;
			if(l>cnt)
			{
				ll k1 = 0, k2 = 0;
				k1 = (-cnt+sqrtl(powl(cnt,2)+4*(l)))/2;
				//k1++;
				k2 = (-cnt-1+sqrtl(powl(cnt+1,2)+4*r))/2;
				k = k1+k2;
				
				l-=(cnt*((k1))+powl((k1),2));
				r-=(cnt*k2+k2+powl(k2,2));
			}
			cout << "Case #" << h-t << ": " << cnt+k << " " << l << " " << r << endl;

		}
		else
		{
			ll diff = r-l;
			ll root = sqrtl(1+8*diff);
			ll cnt = (root-1)/2;
			r-=(cnt*(cnt+1))/2;
			if(r>l && r>cnt)
			{
				cnt++;
				r-=cnt;
			}
			//cout << "cnt: " << cnt << endl;
			ll k = 0;
			if(l>cnt)
			{
				ll k1 = 0, k2 = 0;
				k1 = (-cnt+sqrtl(powl(cnt,2)+4*(l)))/2;
				k2 = (-cnt-1+sqrtl(powl(cnt+1,2)+4*r))/2;
				k = k1+k2;
				
				l-=(cnt*(k1)+powl(k1,2));
				r-=(cnt*k2+k2+powl(k2,2));
			}
			cout << "Case #" << h-t << ": " << cnt+k << " " << l << " " << r << endl;
		}
		
	}
	return 0;
}