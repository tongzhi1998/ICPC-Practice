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

int K;

string manip(string& s)
{
	int n = s.length();
	for(int i=0;i<n;++i)
	{
		char min = s[i];
		int index = -1;
		for(int j=i+1;j<n;++j)
		{
			if(s[j]<=min && index!=-1)
			{
				min = s[j];
				index = j;
			}
			else if(index==-1 && s[j]<min)
			{
				min = s[j];
				index = j;
			}
		}
		if(index!=-1)
		{
			swap(s[i],s[index]);
			break;
		}
	}
	return s;
}

int main()
{
	cin>>K;
	while(K--)
	{
		string s,c;
		cin>>s>>c;
		s = manip(s);
		if(s<c)
		{
			cout << s << endl;
		}
		else
		{
			cout << "---" << endl;
		}
	}
	return 0;
}