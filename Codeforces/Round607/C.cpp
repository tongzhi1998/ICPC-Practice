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

int mod = 1000000007;

int K;

int main()
{
	cin>>K;
	for(int i=0;i<K;++i)
	{
		int n;
		string s;
		cin>>n>>s;
		long long over = 0;
		for(int j=0;j<n;++j)
		{
			int temp = s[j]-'0';
			if(over==0)
			{
				string to_copy = s.substr(j+1);
				for(int k=0;k<temp-1;++k)
				{
					if(s.length()<n)
					{
						s+=to_copy;
					}
					else
					{
						if(over == 0)
						{ 
							over =  s.length()+to_copy.length();
						}
						else
						{
							over+=to_copy.length();
						}
					}
				}
			}
			else
			{
				long long record = (over-j-1+mod)%mod;
				for(int k=0;k<temp-1;++k){
					over+=record;
					over = over%mod;
				}
			}
			over = over%mod;
		}
		if(over==0) cout << s.length() << endl;
		else
			cout << over%mod <<endl;
	}
	return 0;
}