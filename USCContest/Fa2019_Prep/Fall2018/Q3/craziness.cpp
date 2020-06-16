#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

double crazy;

void calc(const vector<vector<double>>& v, int n, vector<bool>& choose)
{
	if(choose.size()==n)
	{
		vector<int> temp;
		for(int i=0;i<n;++i)
		{
			if(choose[i]==true)
			{
				temp.emplace_back(i);
			}
		}
		// if(temp.size()==3&&temp[0]==1&&temp[1]==3&&temp[2]==4)
		// {
		// 	cout << "Should be the solution:!!" << endl;
		// }
		if(temp.size()==0)
			return;
		double curr = 0.0;
		for(int i=0;i<temp.size();++i)
		{
			for(int j=i;j<temp.size();++j)
			{
				curr+=v[temp[i]][temp[j]];
			}
			//cout << "curr is: " << curr << endl;
		}
		crazy = max(crazy,curr);
	}
	else
	{
		vector<bool> temp = choose;
		choose.push_back(false);
		temp.push_back(true);
		calc(v,n,choose);
		calc(v,n,temp);
	}
}

int main()
{
	int K;
	ifstream ifile("craziness.in");
	ifile>>K;
	
	ofstream ofile("craziness.out");
	ofile.precision(2);
	for(int i=0;i<K;++i)
	{
		int N;
		ifile>>N;
		vector<vector<double>> v(N);
		for(int i=0;i<N;++i)
		{
			v[i].resize(N);
		}

		for(int i=0;i<N;++i)
		{
			for(int j=0;j<N;++j)
			{
				ifile>>v[i][j];
			}
		}
		crazy = -1000000.0;
		vector<bool> temp; temp.clear();
		calc(v,N,temp);
		ofile<<"Data Set: " << (i+1) << endl;
		ofile << fixed << crazy << endl;

	}
	return 0;
}