#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

int main()
{
	ifstream ifile("cap.in");
	ofstream ofile("cap.out");
	int n;
	ifile>>n;
	for(int i=0;i<n;++i)
	{
		int numCap, numTry;
		ifile>>numCap>>numTry;
		map<int,int> m;
		m.clear();
		ofile << "Data Set " << i+1 << ":" << endl; 
		bool flag = false;
		for(int j=0;j<numCap;++j)
		{
			int temp;
			ifile>>temp;
			m.insert(make_pair(temp,j));
		}
		int p1 = 0, p2 = numCap-1;
		for(int j=0;j<numTry;++j)
		{
			int size, fit;
			ifile>>size>>fit;
			bool unique = false;
			if(fit==0)
			{
				if(m[size]<p1||m[size]>p2)
				{
					flag = true;
					ofile << "Inconsistent feedBack" << endl;
					ofile << endl;
					break;
				}
				else
				{
					p1 = m[size];
					p2 = m[size];
					unique = true;
				}
			}
			else if(fit==-1)
			{
				if(m[size]<p1||(m[size]==p1&&unique))
				{
					flag = true;
					ofile << "Inconsistent feedBack" << endl;
					ofile<< endl;
					break;
				}
				else
				{
					p2 = min(p2,m[size]-1);
				}
			}
			else
			{
				if(m[size]>p2||(m[size]==p2&&unique))
				{
					flag = true;
					ofile << "Inconsistent feedBack" << endl;
					ofile << endl;
					break;
				}
				else
				{
					p1 = max(p1,m[size]+1);
				}
			}
		}
		if(!flag)
		{
			ofile << p2-p1+1 << endl << endl;
		}
	}
	return 0;
}