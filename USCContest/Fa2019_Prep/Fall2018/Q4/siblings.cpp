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
	ifstream ifile("siblings.in");
	ofstream ofile("siblings.out");
	ifile>>K;
	for(int i=0;i<K;++i)
	{
		int n;
		ifile>>n;
		ofile << "Data Set " << i+1 << ":" << endl;
		int ans=0;
		map<int,int> count;
		count.clear();
		for(int j=0;j<n;++j)
		{
			int curr;
			ifile>>curr;
			if(count.find(curr)==count.end())
			{
				count.insert(make_pair(curr,1));
			}
			else
			{
				count[curr]++;
			}
		}
		for(auto it: count)
		{
			if(it.first!=0)
			{
				ans+=it.second*(it.second-1)/2;
			}
		}
		ofile << ans << endl << endl;
	}
	return 0;
}