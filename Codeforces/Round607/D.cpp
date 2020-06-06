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

bool func1(const vector<vector<char>>& v)
{
	int r = v.size(), c = v[0].size();
	bool flag = true;
	for(int i=0;i<r;++i)
	{
		if(v[i][0]=='P')
		{
			flag = false;
			break;
		}
	}
	if(flag)
		return true;
	flag = true;
	for(int i=0;i<r;++i)
	{
		if(v[i][c-1]=='P')
		{
			flag = false;
			break;
		}
	}
	if(flag)
		return true;
	flag = true;
	for(int i=0;i<c;++i)
	{
		if(v[0][i]=='P')
		{
			flag = false;
			break;
		}
	}
	if(flag)
		return true;
	flag = true;
	for(int i=0;i<c;++i)
	{
		if(v[r-1][i]=='P')
		{
			flag = false;
			break;
		}
	}
	if(flag)
		return true;
	return false;
}

bool func2(const vector<vector<char>>& v)
{
	int r = v.size(), c = v[0].size();
	if(v[0][0]=='A' || v[r-1][0]=='A' || v[0][c-1]=='A' || v[r-1][c-1]=='A'){
		return true;
	}
	for(int i=0;i<r;++i)
	{
		bool flag = true;
		for(int j=0;j<c;++j)
		{
			if(v[i][j]=='P')
			{
				flag = false;
				break;
			}
		}
		if(flag) return true;
	}
	for(int i=0;i<c;++i)
	{
		bool flag = true;
		for(int j=0;j<r;++j)
		{
			if(v[j][i]=='P')
			{
				flag = false;
				break;
			}
		}
		if(flag)
			return true;
	}
	return false;
}

bool func3(const vector<vector<char>>& v)
{
	int r = v.size(), c = v[0].size();
	bool flag = false;
	for(int i=0;i<r;++i)
	{
		if(v[i][0]=='A')
		{
			flag = true;
			break;
		}
	}
	for(int i=0;i<r;++i)
	{
		if(v[i][c-1]=='A')
		{
			flag = true;
			break;
		}
	}
	for(int i=0;i<c;++i)
	{
		if(v[0][i]=='A')
		{
			flag = true;
			break;
		}
	}
	for(int i=0;i<c;++i)
	{
		if(v[r-1][i]=='A')
		{
			flag = true;
			break;
		}
	}
	return flag;
}



int main()
{
	cin>>K;
	while(K--)
	{
		int r,c;
		cin>>r>>c;
		vector<vector<char>> v(r);
		int pCount = 0, aCount = 0;
		for(int i=0;i<r;++i){
			v[i].resize(c);
		}
		for(int i=0;i<r;++i)
		{
			for(int j=0;j<c;++j)
			{

				cin>>v[i][j];
				if(v[i][j]=='P')
					++pCount;
				else
					++aCount;
			}
		}
		if(aCount==r*c)
		{
			cout << "0" << endl;
		}
		else if(pCount==r*c)
		{
			cout << "MORTAL" << endl;
		}
		else
		{
			if(func1(v))
			{
				cout << "1" << endl;
			}
			else if(func2(v))
			{
				cout << "2" << endl;
			}
			else if(func3(v))
			{
				cout << "3" << endl;
			}
			else
			{
				cout << "4" << endl;
			}
		}


	}
	return 0;
}