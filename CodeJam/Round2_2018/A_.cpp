/**
 *    author:  tourist
 *    created: 31.03.2018 11:41:48       
**/
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int c;
    cin >> c;
    vector<int> b(c);
    for (int i = 0; i < c; i++) {
      cin >> b[i];
    }
    if (b[0] == 0 || b[c - 1] == 0) {
      cout << "IMPOSSIBLE" << '\n';
      continue;
    }
    vector<int> to;
    for (int i = 0; i < c; i++) {
      for (int j = 0; j < b[i]; j++) {
        to.push_back(i);
      }
    }
    int r = 1;
    for (int i = 0; i < c; i++) {
      r = max(r, abs(i - to[i]) + 1);
    }
    cout << r << '\n';
    vector<string> s(r, string(c, '.'));
    for (int p = 0; p < c; p++) {
      if (to[p] < p) {
        for (int i = 0; i < p - to[p]; i++) {
          s[i][p - i] = '/';
        }
      }
      if (to[p] > p) {
        for (int i = 0; i < to[p] - p; i++) {
          s[i][p + i] = '\\';
        }
      }
    }
    for (int i = 0; i < r; i++) {
      cout << s[i] << '\n';
    }
  }
  return 0;
}