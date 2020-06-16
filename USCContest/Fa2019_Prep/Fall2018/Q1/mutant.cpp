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

int main()
{
	int K;
	ifstream ifile("mutant.in");
	ofstream ofile("mutant.out");
	ifile>>K;
	for(int i=0;i<K;++i)
	{
		ofile << "Data Set " << i+1 << ":" << endl;
		int num,len;
		ifile>> num>>len;
		vector<vector<char>> v;
		vector<char> trait;
		for(int j=0;j<=num;++j)
		{
			char temp;
			if(j==0)
			{
				for(int k=0;k<len;++k)
				{
					ifile>>temp;
					trait.emplace_back(temp);
				}
			}
			else
			{
				vector<char> s; s.clear();
				for(int k=0;k<len;++k)
				{
					ifile>>temp;
					s.emplace_back(temp);
				}
				v.emplace_back(s);
			}
		}
		int count = 0;
		for(int j=0;j<len;++j)
		{
			char curr = trait[j];
			bool found = false;
			for(int k=0;k<num;++k)
			{
				if(v[k][j]==curr)
				{
					found = true;
					break;
				}
			}
			if(!found)
			{
				count++;
			}
		}
		ofile << count << "/" << len << endl << endl;
	}
	return 0;
}