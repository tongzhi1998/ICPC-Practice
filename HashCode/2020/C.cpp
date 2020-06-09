#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
/* Data Structure */
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>

using namespace std;

#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fLL
#define DEBUG cerr << "======= GOT_HERE ======\n"
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int,int> mii;
typedef map<long long,long long> mll;
typedef set<int> si;
typedef set<long long> sll;

// greedy criteria: shortest time first

int B,L,D;

set<int> visited;

struct lib{
	int index;
	int numBook;
	int signUp;
	int speed;
	vector<int> books;
	int currPos;
	vector<int> processed;

	int valRemain;

	lib(int a, int b, int c, int d, vector<int> e, int idx)
	{
		valRemain = 0;
		index = idx;
		numBook = a;
		signUp = b;
		speed = c;
		currPos = d;
		books = e;
		processed.clear();
	}
};

vector<int> values;
vector<lib> libs;


bool cmp2(const lib& a, const lib& b){
		if(abs(a.signUp-b.signUp)>=2)
			return a.signUp < b.signUp;
		return a.valRemain > b.valRemain;
	}

bool cmpValue(int a, int b) // used to sort books
{
	return values[a]>values[b];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	visited.clear();

	ifstream ifile("e_so_many_books.txt");
	ifile>>B>>L>>D;
	values.resize(B);
	for(int i=0;i<B;++i)
	{
		ifile>>values[i];
	}
	for(int i=0;i<L;++i)
	{
		int a, b, c;
		ifile>>a>>b>>c;
		vector<int> bk(a);
		for(int j=0;j<a;++j)
		{
			ifile>>bk[j];
		}
	
		sort(bk.begin(),bk.end(),cmpValue);
		int d = 0;
		lib temp(a,b,c,d,bk,i);
		libs.emplace_back(temp);
	}
	int currD = 0;
	int numLib = 0;

	for(int i=0;i<libs.size();++i)
	{
			for(int j=i;j<libs.size();++j)
			{
				int score = 0;
				for(int k=libs[j].currPos;k<libs[j].books.size();++k)
				{
					if(visited.find(libs[j].books[k])==visited.end())
					{
						score+=values[libs[j].books[k]];
					}
				}
				libs[j].valRemain = score;
			}
			sort(libs.begin()+i,libs.end(),cmp2);
		currD+=libs[i].signUp; // already sign library i up!
		int tLimit = 0;
		tLimit = libs[i].signUp;
		if(currD>=D)
		{
			currD-=libs[i].signUp;
			tLimit = D-currD;
			currD+=libs[i].signUp;
			break;
		}
		for(int j=0;j<i;++j) // can do a lot of improvements here! For library j
		{
			bool flag = false;
			if(libs[j].currPos == libs[j].numBook) continue;
			for(int t=0;t<tLimit;++t)
			{
				for(int s = 0; s<libs[j].speed;++s)
				{
					// debug
					// if(j==1)
					// {
					// 	cout << "pos is: " << libs[j].currPos << endl;
					// }
					if(visited.find(libs[j].books[libs[j].currPos])==visited.end())
					{
						visited.insert(libs[j].books[libs[j].currPos]); // we process a new book!
						libs[j].processed.emplace_back(libs[j].books[libs[j].currPos]);
						libs[j].currPos++;
						if(libs[j].currPos>=libs[j].numBook) // reach the end
						{
							flag = true;
							break;
						} 
					}
					else
					{
						libs[j].currPos++;
						if(libs[j].currPos>=libs[j].numBook)
						{
							flag = true;
							break;
						}
						--s;
					}
				}
				if(flag)
					break;
			}
		}

		if(currD>=D)
			break;
		numLib++;
	}

	if(currD<D)
	{
		int tLimit = D-currD;
		for(int j=0;j<libs.size();++j)
		{
			bool flag = false;
			if(libs[j].currPos == libs[j].numBook) continue;
			for(int t=0;t<tLimit;++t)
			{
				for(int s = 0; s<libs[j].speed;++s)
				{
					// debug
					// if(j==1)
					// {
					// 	cout << "pos is: " << libs[j].currPos << endl;
					// }
					if(visited.find(libs[j].books[libs[j].currPos])==visited.end())
					{
						visited.insert(libs[j].books[libs[j].currPos]); // we process a new book!
						libs[j].processed.emplace_back(libs[j].books[libs[j].currPos]);
						libs[j].currPos++;
						if(libs[j].currPos>=libs[j].numBook) // reach the end
						{
							flag = true;
							break;
						} 
					}
					else
					{
						libs[j].currPos++;
						if(libs[j].currPos>=libs[j].numBook)
						{
							flag = true;
							break;
						}
						--s;
					}
				}
				if(flag)
					break;
			}
		}
	}

	ofstream ofile("output.txt");
	int cnt = 0;
	for(int i=0;i<numLib;++i)
	{
		if(libs[i].processed.size()==0) cnt++;
	}
	ofile << numLib-cnt << endl;

	int ans = 0;
	for(int i=0;i<numLib;++i)
	{ 	
		if(libs[i].processed.size()==0) continue;
		ofile << libs[i].index << " " << libs[i].processed.size() << endl;
		for(int j=0;j<libs[i].processed.size();++j)
		{
			ofile << libs[i].processed[j] << " ";
			ans+=values[libs[i].processed[j]];
		}
		ofile << endl;
	}

	cout << ans << endl;
	return 0;
}