#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
/* Data Structure */
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

int n,k;

int dp[200050][2];

int main()
{
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[1][0] = v[1]>v[0]?2:1;
	dp[1][1] = v[1]>v[0]?2:1;
	int ans = max(dp[1][1],dp[0][1]);
	for(int i=2;i<n;++i)
	{
		if(v[i]>v[i-1])
		{
			dp[i][0] = dp[i-1][0]+1;
			dp[i][1] = dp[i-1][1]+1;
			if(v[i]>v[i-2])
			{
				dp[i][1] = max(dp[i][1],dp[i-2][0]+1);
			}
		}
		else
		{
			if(v[i]<=v[i-2])
			{
				dp[i][0] = 1;
				dp[i][1] = 1;
			}
			else
			{
				if(dp[i-2][0]==dp[i-2][1])
				{
					dp[i][0] = 1;
					dp[i][1] = dp[i-2][0]+1;
				}
				else
				{
					dp[i][0] = 1;
					dp[i][1] = dp[i-2][0]+1;
				}
			}
		}
		ans = max(ans,dp[i][1]);
	}
	cout << ans << endl;
	return 0;
}