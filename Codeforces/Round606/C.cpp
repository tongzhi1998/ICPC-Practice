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

int t;
string s;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>s;
		int ans = 0;
		vector<int> pos;
		if(s.length()<3)
		{
			cout << "0" << endl;
			continue;
		}
		for(int i=0;i<s.length()-2;++i)
		{
			if(s.substr(i,3)=="one")
			{
				pos.emplace_back(i+1);
				ans++;
				i+=2;
			}
			else if(s.substr(i,3)=="two")
			{
				if(i<s.length()-3 && s[i+3]=='o')
				{
					pos.emplace_back(i+1);
					i+=1;
					ans++;
					
				}
				else
				{
					pos.emplace_back(i+2);
					i+=2;
					ans++;
				}
			}
		}
		cout << ans << endl;
		for(int i=0;i<pos.size();++i)
		{
			cout << pos[i]+1 << " ";
		}
		cout << endl;
	}
	return 0;
}