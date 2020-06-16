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
	//ofile.precision(2);
	ifstream ifile("gpa.in");
	ofstream ofile("gpa.out");
	ofile.precision(2);
	int n;
	ifile>>n;
	for(int i=0;i<n;++i)
	{
		ofile << "Data Set " << i+1 << ":" << endl;
		map<string,double> allCourse;
		vector<pair<string,set<string> > > depart;
		int numC, numD, numS;
		ifile>>numC>>numD>>numS;
		for(int j=0;j<numC;++j)
		{
			string title;
			double unit;
			ifile>>title>>unit;
			allCourse.insert(make_pair(title,unit));
		}
		for(int j=0;j<numD;++j)
		{
			string dName;
			int num;
			ifile>>dName>>num;
			set<string> temp;
			for(int k=0;k<num;++k)
			{
				string c;
				ifile>>c;
				temp.insert(c);
			}
			depart.emplace_back(make_pair(dName,temp));
		}
		for(int j=0;j<numS;++j)
		{
			ofile << "Student " << j+1 << endl;
			vector<pair<string,double>> registered;
			int K;
			ifile>>K;
			//cout << K << endl;
			for(int k=0;k<K;++k)
			{
				string name;
				double grade;
				ifile>>name>>grade;
				registered.emplace_back(make_pair(name,grade));
			}
			// calculating overall GPA:
			double GPA = 0;
			double weight = 0;
			for(int k=0;k<registered.size();++k)
			{
				int temp = allCourse[registered[k].first];
				//cout << registered[k].first << endl;
				weight+=temp;
				GPA+=temp*registered[k].second;
			}
			//return 0;
			GPA/=weight;
			ofile << fixed <<"GPA: " << GPA << endl;
			for(int k=0;k<depart.size();++k)
			{
				string title = depart[k].first;
				set<string> temp = depart[k].second;
				bool all = true;
				double points = 0;
				double units = 0;
				for(auto it = temp.begin();it!=temp.end();++it)
				{
					bool found = false;
					string s=*it;
					for(int a=0;a<registered.size();++a)
					{
						if(registered[a].first==s)
						{
							found = true;
							points+=registered[a].second*allCourse[s];
							units+=allCourse[s];
							break;
						}
						if(found)
							break;
					}
					if(!found)
					{
						all=false;
						break;
					}
				}
				if(all)
				{
					ofile<<title<< ": " << fixed <<points/units << endl;
				}
			}
		}
		ofile << endl;
	}
	return 0;
}