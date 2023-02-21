#include <bits/stdc++.h>
using namespace std;

#define null NULL
#define endl "\n"
#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,string> pis;
typedef pair<string,int> psi;
typedef pair<string,string> pss;
typedef vector<pii > vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vi > vvi;
typedef vector<vll > vvll;
typedef map<int, int> mii;
typedef map<string, string> mss;
typedef map<int, string> mis;
typedef map<string, int> msi;
#define mid(l, r) (l + (r - l) / 2)
#define f(i,s,n) for(ll i = s; i <= n; i++)
#define fr(i,s,e) for(ll i = s; i >= e; i--)
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define fi first
#define se second
#define INF 2e18

class Project {
  public:
    ll s, e, r; // s - start, e - end, r - reward
    Project() {
      s = e = r = 0;
    }
};

bool cmp(Project a, Project b) {
  return a.e <= b.e;
}

ll bSearch(ll i, Project p[]) {
  
  ll s = 0, e = i-1, m = 0, idx = -1;
  
  while(s <= e) {
    m = mid(s, e);

    if(p[i].s > p[m].e) {
      idx = m;
      s = m+1;
    } else {
      e = m-1;
    }
  }

  return idx;
}

void solve(ll n, Project p[]) {
  
  vll dp(n, 0);
  sort(p, p+n, cmp);

  ll idx = -1, inc, excl;

  dp[0] = p[0].r; // include first activity;

  f(i, 1, n-1) {
    
    idx = bSearch(i, p);
    
    inc = p[i].r;
    excl = dp[i-1];
    
    if(idx != -1) {
      inc += dp[idx];
    }

    dp[i] = max(inc, excl);
  }

  cout<<dp[n-1]<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin >> n;

  Project p[n];

  f(i, 0, n-1) {
    cin>>p[i].s>>p[i].e>>p[i].r;
  }

  solve(n, p);

  return 0;
}
