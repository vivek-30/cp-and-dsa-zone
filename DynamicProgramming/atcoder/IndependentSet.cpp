#include <bits/stdc++.h>
using namespace std;

#define null NULL
#define endl "\n"
#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
typedef pair<string, string> pss;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef map<string, string> mss;
typedef map<int, string> mis;
typedef map<string, int> msi;
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, n) for (ll i = s; i <= n; i++)
#define fr(i, s, e) for (ll i = s; i >= e; i--)
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int>>
#define fi first
#define se second
#define INF 2e18

ll dp[100005][2];
vi g[100005];

void solve(int src, int parent) // 0 - white, 1 - black
{
  dp[src][0] = dp[src][1] = 1;

  for(int child: g[src]) {
    if(child != parent) {
      solve(child, src);
      dp[src][0] = dp[src][0]*(dp[child][0] + dp[child][1])%mod;
      dp[src][1] = (dp[src][1]*dp[child][0])%mod;
    }
  }
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int v;
  cin >> v;

  f(i, 1, (v - 1))
  {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }

  solve(1, -1);
  cout<<((dp[1][0] + dp[1][1])%mod)<<endl;

  return 0;
}
