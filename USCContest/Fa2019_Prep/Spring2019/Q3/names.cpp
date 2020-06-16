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
	int n;
	ifstream ifile("names.in");
	ofstream ofile("names.out");
	ifile>>n;
	for(int i=0;i<n;++i)
	{
		ofile << "Data Set " << i+1 << ":" << endl;
		int ans = 0;
		int numS, len;
		ifile>>len>>numS;
		//cout << numS << " "<<len << endl;
		int matrix[len+1][len+1];
		for(int j=0;j<len+1;++j)
		{
			for(int k=0;k<len+1;++k)
			{
				ifile>>matrix[j][k];
				//cout << matrix[j][k] << " ";
			}
			//cout << endl;
		}
		string temp;
		getline(ifile,temp);
		for(int m=0;m<numS;++m)
		{
			string name;
			getline(ifile,name);
			while(name.length()==0)
			{
				ans+=matrix[0][0];
				if(m==numS-1)
				{
					break;
				}
				getline(ifile,name);
				m++;
			}
			int vowel=0, con=0;
			//cout << name <<endl;
			for(int j=0;j<name.length();++j)
			{
				if(name[j]=='a'||name[j]=='e'||name[j]=='i'||name[j]=='o'||name[j]=='u'||name[j]=='y')
				{
					vowel++;
				}
				else
				{
					con++;
				}
			}
			ans+=matrix[vowel][con];
		}
		ofile << ans << endl;
		//getline(ifile,temp);
	}
	return 0;
}