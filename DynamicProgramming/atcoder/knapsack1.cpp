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

ll solve2(ll n, ll w, vll &price, vll &weight, vvll &dp) {

  if(w <= 0 or n <= 0)
    return 0;

  if(dp[n][w] != minf) 
    return dp[n][w];

  if(w - weight[n-1] >= 0) {
    dp[n][w] = max(solve2(n-1, w, price, weight, dp), price[n-1] + solve2(n-1, w - weight[n-1], price, weight, dp));
  }else {
    dp[n][w] = solve2(n-1, w, price, weight, dp);
  }

  return dp[n][w];
}

void solve(ll n, ll w, vll &price, vll &weight) {

  vvll dp(n+1, vll(w+1, 0));

  f(i, 1, n) {
    f(j, 1, w) {
      if(j - weight[i-1] >= 0) {
        dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i-1][j-weight[i-1]]);
      }else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  cout<<dp[n][w]<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n, w;
  cin>>n>>w;

  vll price(n), weight(n);

  f(i, 0, n-1) {
    cin>>weight[i]>>price[i];
  }
  
  vvll dp(n+1, vll(w+1, minf));
  // cout<<solve2(n, w, price, weight, dp)<<endl;
  solve(n, w, price, weight);

  return 0;
}
