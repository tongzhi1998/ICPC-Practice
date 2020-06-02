#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int cnt[10];

int main()
{
	for(int i=1;i<=4999;++i)
	{
		string s = to_string(i);
		for(int j=0;j<s.length();++j)
		{
			cnt[s[j]-'0']++;
		}
	}
	for(int i=0;i<10;++i)
	{
		cout << i << " " << cnt[i] << endl;
	}
	return 0;
}