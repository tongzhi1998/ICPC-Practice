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

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;

int n,t;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		int temp = n;
		int cnt = 0;
		int ans = 0;
		int r  = -1;
		while(temp!=0)
		{
			cnt++;
			if(temp<10)
			{
				r = temp;
			}
			temp/=10;
		}
		cnt--;
		ans+=9*cnt;
		string made;
		for(int i=0;i<cnt+1;++i)
		{
			made+=r+'0';
		} 
		if(cnt==0)
		{
			ans = n;
		}
		else
		{
			if(stoi(made)<=n)
			{
				ans+=r;
			}
			else
			{
				ans+=(r-1);
			}
		}
		cout << ans << endl;

	}
	return 0;
}