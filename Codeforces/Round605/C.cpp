#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <cmath>

using namespace std;

int k,n;

int main()
{
	cin>>n>>k;
	string s;
	set<char> contain;
	s.reserve(n);
	for(int i=0;i<n;++i)
	{
		cin>>s[i];
	}
	for(int i=0;i<k;++i)
	{
		char c;
		cin>>c;
		contain.insert(c);
	}
	vector<long long> v;
	int count = 0;
	for(int i=0;i<n;++i)
	{
		if(contain.find(s[i])!=contain.end())
		{
			count++;
		}
		else
		{
			v.emplace_back(count);
			count = 0;
		}
	}
	v.emplace_back(count);
	long long ans = 0;
	for(int i=0;i<v.size();++i)
	{
		long long a=v[i], b=v[i]+1;
		if(a%2==0)
			a/=2;
		else
			b/=2;
		ans+=(a*b);
	}
	cout << ans << endl;

	return 0;
}