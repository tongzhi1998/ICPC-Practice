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

int t,n;

int cnt[2][2];

int main()
{
	cin>>t;
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		bool flag = true;
		cin>>n;
		vector<string> v(n);
		set<string> s;
		int ans = 0;
		vector<int> pos;
		for(int i=0;i<n;++i)
		{
			cin>>v[i];
			s.insert(v[i]);
			cnt[v[i][0]-'0'][v[i][v[i].length()-1]-'0']++;
		}
		if(cnt[0][1]-cnt[1][0]<=1 && cnt[1][0]-cnt[0][1]<=1)
		{
			if(!(cnt[0][1]==0 && cnt[1][0]==0 && cnt[1][1]!=0 && cnt[0][0]!=0))
			{
				cout << "0" << endl;
				continue;
			}
			else
			{
				cout << "-1" << endl;
				continue;
			}
		}
		else if(cnt[0][1]-cnt[1][0]>1)
		{
			ans = (cnt[0][1]-cnt[1][0])/2;
			int count = 0;
			for(int i=0;i<n;++i)
			{
				string str = v[i];
				if(str[0]=='0' && str[str.length()-1]=='1')
				{
					reverse(str.begin(),str.end());
					if(s.find(str)==s.end())
					{
						count++;
						pos.emplace_back(i+1);
					}
				}
				if(count>=ans)
				{
					cout << ans << endl;
					for(int i=0;i<ans;++i)
					{
						cout << pos[i] << " ";
					}
					cout << endl;
					break;
				}
			}
			if(count<ans)
			{
				cout << "-1" << endl;
			}
		}
		else
		{
			ans = (cnt[1][0]-cnt[0][1])/2;
			int count = 0;
			for(int i=0;i<n;++i)
			{
				string str = v[i];
				if(str[0]=='1' && str[str.length()-1]=='0')
				{
					reverse(str.begin(),str.end());
					if(s.find(str)==s.end())
					{
						count++;
						pos.emplace_back(i+1);
					}
				}
				if(count>=ans)
				{
					cout << ans << endl;
					for(int i=0;i<ans;++i)
					{
						cout << pos[i] << " ";
					}
					cout << endl;
					break;
				}
			}
			if(count<ans)
			{
				cout << "-1" << endl;
			}
		}
	}
	return 0;
}