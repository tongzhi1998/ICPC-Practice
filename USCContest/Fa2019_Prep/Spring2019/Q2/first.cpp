
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
#include <queue>

using namespace std;

int main()
{
	//ofile.precision(2);
	ifstream ifile("first.in");
	ofstream ofile("first.out");
	int n;
	ifile>>n;
	for(int i=0;i<n;++i)
	{
		ofile << "Data Set " << i+1 << ":" << endl;
		map<string,int> color;
		map<string,set<string>> adj_list;
		vector<pair<string,string>> record;
		int num;
		ifile>>num;
		for(int j=0;j<num;++j)
		{
			string s,t;
			ifile>>s>>t;
			record.emplace_back(make_pair(s,t));
			if(color.find(s)==color.end())
			{
				color.insert(make_pair(s,-1));
			}
			if(color.find(t)==color.end())
			{
				color.insert(make_pair(t,-1));
			}
			if(adj_list.find(s)==adj_list.end())
			{
				set<string> temp{t};
				adj_list.insert(make_pair(s,temp));
			}
			else
				adj_list[s].insert(t);
			if(adj_list.find(t)==adj_list.end())
			{
				set<string> temp{s};
				adj_list.insert(make_pair(t,temp));
			}
			else
				adj_list[t].insert(s);
		}
		int ans1 = 0, ans2 = 0;
		bool flag = true;
		// cout << "adj_list:" << endl;
		// for(auto it:adj_list)
		// {
		// 	cout << it.first << " ";
		// 	for(auto it2: it.second)
		// 		cout << it2 << " ";
		// 	cout << endl;
		// }
		queue<string> q;
		set<string> visited;
		int ans = 0;
		while(visited.size()<color.size())
		{
			auto it1 = color.begin();
			while(color[it1->first]!=-1)
			{
				it1++;
			}
			color[it1->first] = 0;
			ans1 = 0;
			ans2 = 0;
			set<string> temp1;
			q.push(it1->first);
			visited.insert(it1->first);
			temp1.insert(it1->first);
			while(!q.empty())
			{
				string temp = q.front();
				int c = color[temp];
				q.pop();
				for(auto it = adj_list[temp].begin();it!=adj_list[temp].end();++it)
				{
					if(visited.find(*it)==visited.end()){
						q.push(*it);
						visited.insert(*it);
						temp1.insert(*it);
					}
					if(color[*it]==-1)
					{
						color[*it] = c^1;
					}	
					else if(color[*it]==c)
					{
						flag = false;
						break;
					}
					else
						continue;
				}
			}
			for(int j=0;j<num;++j)
			{
				pair<string,string> temp = record[j];
				if(color[temp.first]==1&&temp1.find(temp.first)!=temp1.end())
					ans1++;
			}
			for(int j=0;j<num;++j)
			{
				pair<string,string> temp = record[j];
				if(color[temp.first]==0&&temp1.find(temp.first)!=temp1.end())
					ans2++;
			}
			ans += min(ans1,ans2);
		}
		if(!flag)
		{
			ofile << "Impossible" << endl << endl;
			continue;
		}
		ofile << ans << endl << endl;
	}
	return 0;
}

/*

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

struct bfs_obj{
	int node;
	int to_label;
	bfs_obj(int n, int t) : node(n), to_label(t) {}
};

// returns -1 if not possible
// pass things by reference... jk maybe later
// this function will do everything and modify everything?
int num_swaps(map<int, vector<int> >& edges, map<int, int>& first_counts, map<int, int>& last_counts, vector<int>& assigned, int i) {
	int first_score = 0, last_score = 0;
	vector<int> as_first = assigned, as_last = assigned;
	queue<bfs_obj> q;
	q.push(bfs_obj(i, -1));
	
	while (!q.empty() && first_score != -1) {
		bfs_obj cur = q.front();
		q.pop();
		
		if (as_first[cur.node] == 0) {
			as_first[cur.node] = cur.to_label;
			if (cur.to_label == -1) first_score += last_counts[cur.node];
			else first_score += first_counts[cur.node];
		}
		else if (as_first[cur.node] == cur.to_label) continue;
		else if (as_first[cur.node] != cur.to_label) {
			first_score = -1;
			break;
		}
		
		vector<int> neigh = edges[cur.node];
		for (int n=0; n<neigh.size(); n++){
			int nei = neigh[n];
			if (as_first[nei] != 0 && as_first[nei] != cur.to_label) continue; //already correct
			else if (as_first[nei] != 0 && as_first[nei] == cur.to_label) {
				first_score = -1;
				break;
			}
			else {
				q.push(bfs_obj(nei, cur.to_label*-1));
			}
		}
	}
	
	// Set up for second run
	while (!q.empty()) q.pop();
	q.push(bfs_obj(i, 1));
	
		while (!q.empty() && last_score != -1) {
		bfs_obj cur = q.front();
		q.pop();
		
		if (as_last[cur.node] == 0) {
			as_last[cur.node] = cur.to_label;
			if (cur.to_label == -1) last_score += last_counts[cur.node];
			else last_score += first_counts[cur.node];
		}
		else if (as_last[cur.node] == cur.to_label) continue;
		else if (as_last[cur.node] != cur.to_label) {
			last_score = -1;
			break;
		}
		
		vector<int> neigh = edges[cur.node];
		for (int n=0; n<neigh.size(); n++){
			int nei = neigh[n];
			if (as_last[nei] != 0 && as_last[nei] != cur.to_label) continue; //already correct
			else if (as_last[nei] != 0 && as_last[nei] == cur.to_label) {
				last_score = -1;
				break;
			}
			else {
				q.push(bfs_obj(nei, cur.to_label*-1));
			}
		}
	}
	
	if (first_score == -1 && last_score == -1) return -1;
	else if (first_score == -1) {
		assigned = as_last;
		return last_score;
	}
	else if (last_score == -1) {
		assigned = as_first;
		return first_score;
	}
	else if (first_score < last_score) {
		assigned = as_first;
		return first_score;
	}
	else {
		assigned = as_last;
		return last_score;
	}
}

int main() {
	fstream fin("first.in"); 

	int k;
	fin >> k;
	
	for (int kk=0; kk<k; kk++) {
		cout << "Data Set " << kk+1 << ":\n";
		
		map<int, vector<int> > edges; 
		map<int, int> first_counts, last_counts;
		map<string, int> name_map;
		//need visited array, same size as names. basically loop through and do bfs.
		//need helper function, visited array also keeps track of what each thing is called.
		
		int n;
		fin >> n;
		
		for (int i=0; i<n; i++) {
			string a, b;
			fin >> a >> b;
			
			if (name_map.find(a) == name_map.end()) name_map[a] = name_map.size();
			if (name_map.find(b) == name_map.end()) name_map[b] = name_map.size();
			
			int an = name_map[a], bn = name_map[b];
			
			first_counts[an]++;
			last_counts[bn]++;
			
			edges[an].push_back(bn);
			edges[bn].push_back(an);
		}
		
		vector<int> assigned(name_map.size(), 0); // -1 is first name, 1 is last name
		int tot_swaps = 0;
		
		bool possible = true;
		for (int i=0; i<name_map.size(); i++) {
			if (assigned[i] != 0) continue;
			int result = num_swaps(edges, first_counts, last_counts, assigned, i);
			if (result == -1) {
				possible = false;
				break;
			}
			else tot_swaps += result;
		}
		
		if (!possible) {
			cout << "Impossible\n\n";
			continue;
		}
		cout << tot_swaps/2 << endl;
		cout << endl;
	}
}
*/