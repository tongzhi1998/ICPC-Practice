#include <iostream>
#include <queue>
#include <assert.h>   
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cstdio>
using namespace std;
#define ll long long
#define ld long double 
#define pi pair<int, int> 
#define pl pair<ll,ll>  
#define pd pair<ld,ld> 
#define str string  
#define mp make_pair
#define vi vector<int> 
#define vl vector<ll> 
#define vd vector<ld> 
#define vs vector<str> 
#define vpi vector<pi> 
#define vpl vector<pl> 
#define vpd vector<pd> 
#define si set<int> 
#define FF(i,j,n) for(signed i=j;i<=n;i++)  
#define DD(i,j,n) for(signed i=j;i>=n;i--) 
#define F(i,j,n) for(signed i=j;i<n;i++)   
#define D(i,j,n) for(signed i=j;i>n;i--) 
#define mem(a,b) memset(a,b,sizeof(a))
#define ndl cout << endl
#define ull unsigned long long 

const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;


#define sz(x) (signed)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back() 
#define fi first
#define se second
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//math
const int mod = 1e9 + 7;

ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 


//DEBUG, compile with -DLOCAL
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
  cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
  DBG(t...); }
#ifdef LOCAL 
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define HERE cout << "===GOTHERE===" << endl
#else
#define dbg(...) 42
#define HERE 42
#endif

//#define double long double
#define int long long
//#define int unsigned long long

const int maxn = 1e5*2+20;

int n,_,q,k;
int a[maxn], b[maxn], c[maxn];
int an,bn,cn;

void init(){
  cin >> _;
  while(_--){
    cin >> an >> bn >> cn;
    F(i,0,an) cin >> a[i];
    F(i,0,bn) cin >> b[i];
    F(i,0,cn) cin >> c[i];
    sort(a,a+an);
    sort(b,b+bn);
    sort(c,c+cn);
    int ans = INF;


    F(i,0,an){
      int val = a[i];
      vi bp, cp;
      if(upper_bound(b,b+bn,val) - b != 0){
        bp.eb(b[upper_bound(b,b+bn,val) - b - 1]);
      }
      if(lower_bound(b,b+bn,val)- b != bn){
        bp.eb(b[lower_bound(b,b+bn,val)- b]);
      }
      if(upper_bound(c,c+cn,val) - c != 0){
        cp.eb(c[upper_bound(c,c+cn,val) - c - 1]);
      }
      if(lower_bound(c,c+cn,val)- c != cn){
        cp.eb(c[lower_bound(c,c+cn,val)- c]);
      } 

      for(int ci : cp){
        for(int bi : bp){
          ans = min(ans, (val-ci)*(val-ci) + (val-bi)*(val-bi) + (ci-bi)*(ci-bi));
        }
      }
    }
    F(i,0,bn){
      int val = b[i];
      vi ap, cp;
      if(upper_bound(a,a+an,val) - a != 0){
        ap.eb(a[upper_bound(a,a+an,val) - a - 1]);
      }
      if(lower_bound(a,a+an,val)- a != an){
        ap.eb(a[lower_bound(a,a+an,val)- a]);
      }
      if(upper_bound(c,c+cn,val) - c != 0){
        cp.eb(c[upper_bound(c,c+cn,val) - c - 1]);
      }
      if(lower_bound(c,c+cn,val)- c != cn){
        cp.eb(c[lower_bound(c,c+cn,val)- c]);
      } 

      for(int ci : ap){
        for(int bi : cp){
          ans = min(ans, (val-ci)*(val-ci) + (val-bi)*(val-bi) + (ci-bi)*(ci-bi));
        }
      }
    }
    F(i,0,cn){
      int val = c[i];
      vi bp, ap;
      if(upper_bound(b,b+bn,val) - b != 0){
        bp.eb(b[upper_bound(b,b+bn,val) - b - 1]);
      }
      if(lower_bound(b,b+bn,val)- b != bn){
        bp.eb(b[lower_bound(b,b+bn,val)- b]);
      }
      if(upper_bound(a,a+an,val) - a != 0){
        ap.eb(a[upper_bound(a,a+an,val) - a - 1]);
      }
      if(lower_bound(a,a+an,val)- a != an){
        ap.eb(a[lower_bound(a,a+an,val)- a]);
      } 

      for(int ci : ap){
        for(int bi : bp){
          ans = min(ans, (val-ci)*(val-ci) + (val-bi)*(val-bi) + (ci-bi)*(ci-bi));
        }
      }
    }

    cout << ans << endl;
  }
}

signed main(){
  //clock_t t1 = clock();  
	IOS
	init();
  //cout << "THE ALGORITHM TOOK: " << (clock() - t1) * 1.0 / CLOCKS_PER_SEC * 1000 << "ms"<< endl;
	return 0;
}