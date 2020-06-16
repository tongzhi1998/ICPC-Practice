#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>

using namespace std;

double m[1050][1050];
double ans = 0;

double compute(vector<int>& v)
{
	double res = 0;
	for(int i=0;i<v.size();++i)
	{
		for(int j=i;j<v.size();++j)
		{
			res+=m[v[i]][v[j]];
		}
	}
	return res;
}

void helper(int index, int total, vector<int> selected)
{
	if(index==total)
	{
		ans = max(ans,compute(selected));
		return;
	}
	selected.emplace_back(index);
	helper(index+1,total,selected);
	selected.pop_back();
	helper(index+1,total,selected);
}

int main()
{
	int K;
	cout.precision(2);
	ifstream ifile("craziness.in");
	ofstream ofile("craziness.out");
	ofile.precision(2);
	ifile>>K;
	for(int i=0;i<K;++i)
	{
		ofile << "Data Set " << i+1 << ":" << endl;
		int n;
		ifile>>n;
		//memset(m,0,sizeof(m));
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<n;++k)
			{
				ifile>>m[j][k];
			}
		}
		vector<int> temp;
		temp.clear();
		helper(0,n,temp);
		if(ans==0)
		{
			double ma = (double)INT_MIN;
			for(int j=0;j<n;++j)
			{
				ma = max(ma,m[j][j]);
			}
			ofile << fixed <<ma << endl << endl;
		}
		else
		{
			ofile << fixed<< ans << endl << endl;
		}
		ans = 0;
	}
	return 0;
}