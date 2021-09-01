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

int dp[105][105][2];

int solve(int n, int k, int prev) {
  if(n == 0) {
    return 0;
  }
  if(n == 1) {
    if(k == 0)
      return 1;
    else return 0;
  }

  if(dp[n][k][prev] != -1)
    return dp[n][k][prev];

  int ans = 0;
  if(prev == 0) {
    ans = solve(n-1, k, 0) + solve(n-1, k, 1);
  } else {
    ans = solve(n-1, k, 0) + solve(n-1, k-1, 1);
  }

  return dp[n][k][prev] = ans;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k, t, q;
  cin >> q;
  f(i, 1, q) {
    
    cin>>t>>n>>k;

    memset(dp, -1, sizeof(dp));

    ll ans = solve(n, k, 0);
    ans += solve(n, k, 1);
    cout<<t<<" "<<ans<<endl;
  }

  return 0;
}
