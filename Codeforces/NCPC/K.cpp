#include <algorithm>
#include <climits>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <bitset>
/*  Data Structures */
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector< vector<int> > vvi;
typedef vector< vector<ll> > vvl;
typedef set<int> si;
typedef set<ll> sl;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define REP(i, x) for (int i=0; i<x; ++i)
#define FOR(i, x, y) for (int i=x; i<y; ++i)
#define sort(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fLL
#define DEBUG cerr << "======= GOT_HERE ======\n"
 
ll a, b;
 
const int MOD = 1e9+7;

ll dp[2510][2510];

void compute()
{
    dp[0][0] = 1;
    for(int i=1;i<=2500;++i)
    {
        dp[i][0] = 1;
    }
    for(int i=1;i<=2500;++i)
    {
        for(int j=1;j<=i;++j)
        {
            dp[i][j] = dp[i-1][j-1];
            if(i-1>=j)
            {
                dp[i][j]+=dp[i-1][j];
            }
            dp[i][j]%=MOD;
        }
    }
    for(int j=0;j<=10;++j)
    {
        cout << dp[2500][j] << " "; 
    }
    cout << endl;

}
 
ll fastExp(ll base, ll p, int mod){
    if(p == 0) return 1;
    else if(p == 1) return base%mod;
    else{
        ll res = fastExp(base, p/2, mod)%mod;
        res *= res;
        res %= mod;
        if(p%2 == 1){res *= base; res %= mod;} 
        return res%mod;
    }
}

 
int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    compute();
    cin >> a >> b;
    REP(i, a-1) {
        int c;
        cin >> c;
    }
    ll ans = 0;
    int count = 1;
    for (ll i=b; i>1; --i) {
        ll curr = fastExp(i-1, a-1, MOD);

        ll toAdd = i;
        toAdd*=curr;
        toAdd%=MOD;
        toAdd*=dp[b][i];
        toAdd%=MOD;

        ans+=MOD;
        if(count&1)
            ans += toAdd;
        else
            ans -= toAdd;
        if(ans<0)
        {
            cout << "!~~" << endl;
            return 0;
        }
        count++;
        ans %= MOD; 
    }
    cout << ans << endl;
    return 0;
}