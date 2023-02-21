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

int solve(int src, vi g[], vi &dp) {

  if(dp[src] != -1)
    return dp[src];

  int res = minf;
  bool is_single = true;

  for(int child : g[src]) {
    is_single = false;
    res = max(res, solve(child, g, dp));
  }

  if(is_single)
    return dp[src] = 0; // No outgoing edge so path is 0 from this vertex.
  else return dp[src] = res + 1;

}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll v, e;
  cin>>v>>e;

  vi g[v+1];
  f(i, 1, e) {
    int a, b;
    cin>>a>>b;

    g[a].pb(b);
  }

  vi dp(v+1, -1);
  int res = minf;

  f(i, 1, v) {
    res = max(res, solve(i, g, dp));
  }

  cout<<res<<endl;

  return 0;
}
