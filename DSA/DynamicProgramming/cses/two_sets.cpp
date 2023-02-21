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
typedef vector<vector<int> > vvi;
typedef vector<pii > vii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef map<string, string> mss;
typedef map<int, string> mis;
typedef map<string, int> msi;
#define mid(l, r) (l + (r - l) / 2)
#define f(i,s,n) for(ll i = s; i <= n; i++)
#define fr(i,s,n) for(ll i = e; i >= s; i--)
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define fi first
#define se second
#define INF 2e18

ll solve1(int n, ll sum, vector<vll> &dp) {

  if(n <= 0 or sum < 0)
    return 0;

  if(sum == 0)
    return 1;

  if(dp[n][sum] != inf)
    return dp[n][sum];

  ll w1 = solve1(n-1, sum, dp);
  ll w2 = solve1(n-1, sum - n, dp);

  dp[n][sum] = (w1 % mod + w2 % mod) % mod;

  return dp[n][sum];
}

void solve2(int n, ll sum) {
  
  vector<vll > dp(n+1, vll(sum+1, 0));

  dp[0][0] = 1;

  f(i, 1, n) {
    f(j, 1, sum) {
      if(j-i >= 0) {
        dp[i][j] = (dp[i-1][j] % mod + dp[i-1][j-i] % mod) % mod;
      }
      else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  cout<<dp[n][sum]<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin>>n;

  ll sum = (n * (n+1)) / 2;
  if(sum & 1)
    cout<<0<<endl;
  else {
    sum /= 2;
    vector<vll> dp(n+1, vll(sum+1, inf));
    // cout<<solve1(n, sum, dp)<<endl;
    solve2(n, sum);
  }

  return 0;
}
