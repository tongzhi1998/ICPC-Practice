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

int main()
{
	cin>>K;
	string dummy;
	getline(cin,dummy);
	for(int i=0;i<K;++i)
	{
		string seq;
		getline(cin,seq);
		int u=0,d=0,l=0,r=0;
		int n = seq.length();
		int num = 0;
		for(int j=0;j<seq.length();++j)
		{
			if(seq[j]=='U')
				++u;
			if(seq[j]=='D')
				++d;
			if(seq[j]=='L')
				++l;
			if(seq[j]=='R')
				++r;
		}
		if(u==0||d==0)
		{
			if(l==0||r==0)
			{
				cout << "0" << endl;
			}
			else
			{
				num = 2;
				cout << num << endl;
				cout << "LR" << endl;
			}
		}
		else if(l==0||r==0)
		{
			if(u==0||d==0)
			{
				cout << "0" << endl;
			}
			else
			{
				num = 2;
				cout << num << endl;
				cout << "UD" << endl;
			}
		}
		else
		{
			int minV = min(l,r), minH = min(u,d);
			cout << 2*(minV+minH) << endl;
			for(int j=0;j<minV;++j)
			{
				cout << "L";
			}
			for(int j=0;j<minH;++j)
			{
				cout << "U";
			}
			for(int j=0;j<minV;++j)
			{
				cout << "R";
			}
			for(int j=0;j<minH;++j)
			{
				cout << "D";
			}
			cout << endl;
		}

	}
	return 0;
}