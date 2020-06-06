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
		string s;
		getline(cin,s);
		int n = s.length();
		if(s.substr(n-2)=="po")
		{
			cout << "FILIPINO" << endl;
		}
		else if(s.substr(n-4)=="desu"||s.substr(n-4)=="masu")
		{
			cout << "JAPANESE" << endl;
		}
		else
		{
			cout << "KOREAN" << endl;
		}
	}
	return 0;
}