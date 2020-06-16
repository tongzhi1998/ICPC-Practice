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
#include <cmath>

using namespace std;

int dp[505][505][2]; // male = 0; female = 1;

int pow(int a, int b)
{
	return a*a;
}

int main()
{
	int K;
	ifstream ifile("portrait.in");
	ofstream ofile("portrait.out");
	ifile>>K;
	for(int i=0;i<K;++i)
	{
		int m,w;
		ifile>>m>>w;
		for(int j=1;j<=m;++j)
		{
			for(int k=1;k<=w;++k)
			{
				dp[j][k][0] = 1000000;
				dp[j][k][1] = 1000000;
			}
		}
		ofile << "Data Set " << i+1 << ":" << endl;
		dp[0][0][0] = 0;
		dp[0][0][1] = 0;
		dp[1][0][0] = w>m?1000000:0; // first is male
		dp[0][1][1] = 0; // first is female
		int man[m];
		int woman[w];
		for(int j=0;j<m;++j)
			ifile>>man[j];
		for(int j=0;j<w;++j)
			ifile>>woman[j];
		int capa = w/(m+1);
		int fill = w%(m+1);
		int sum = 0;
		for(int k=2;k<=capa+1;++k)
		{
			sum+=pow((woman[k-1]-woman[k-2]),2);
			dp[0][k][1] = sum;
		}
		for(int j=1;j<=m;++j)
		{
			for(int k=j*capa;k<=(j+1)*capa+min(j+1,fill);++k)
			{
				int ans1, ans2;
				if(k==j*capa)
				{
					dp[j][k][0] = dp[j-1][k][1]+pow((man[j-1]-woman[k-1]),2);
				}
				else if(k==j*capa+1)
				{
					dp[j][k][1] = dp[j][k-1][0]+pow((man[j-1]-woman[k-1]),2);
					dp[j][k][0] = min((dp[j-1][k][1]+pow((man[j-1]-woman[k-1]),2)),(dp[j][k-1][1]+pow((man[j-1]-woman[k-1]),2)));
				}
				else if(k==(j+1)*capa+min(j+1,fill))
				{
					dp[j][k][1] = min(dp[j][k-1][0]+pow((man[j-1]-woman[k-1]),2), dp[j][k-1][1]+pow((woman[k-1]-woman[k-2]),2));
				}
				else
				{
					dp[j][k][0] = min((dp[j-1][k][1]+pow((man[j-1]-woman[k-1]),2)),(dp[j][k-1][1]+pow((man[j-1]-woman[k-1]),2)));
					ans1 = min(dp[j][k-1][0]+pow((man[j-1]-woman[k-1]),2), dp[j][k-1][1]+pow((woman[k-1]-woman[k-2]),2));
					ans2 = dp[j-1][k][1]+pow((man[j-1]-woman[k-1]),2);
					dp[j][k][1] = min(ans1,ans2);
				}
			}
		}
		cout << dp[m][w][0] << " " << dp[m][w][1] << endl;
		// DEBUG
		for(int a=1;a<=m;++a)
		{
			for(int b=1;b<=w;++b)
			{
				cout << dp[a][b][1] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for(int a=1;a<=m;++a)
		{
			for(int b=1;b<=w;++b)
			{
				cout << dp[a][b][0] << " ";
			}
			cout << endl;
		}
		ofile<<min(dp[m][w][0],dp[m][w][1])<<endl<<endl;
	}
}