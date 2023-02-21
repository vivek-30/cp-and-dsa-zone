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

int solve(int n, int k, vi &arr, vvi &dp) {

  if(k == 0 and n >= 0)
    return 1;

  if(n <= 0)
    return 0;
  
  if(dp[n][k] != inf)
    return dp[n][k];

  if(k - arr[n-1] >= 0)
    dp[n][k] = solve(n-1, k, arr, dp) + solve(n-1, k - arr[n-1], arr, dp);
  else dp[n][k] = solve(n-1, k, arr, dp);

  return dp[n][k];
}

void solve2(int n, int k, vi &arr) {
  
  vvi dp(n+1, vi(k+1, 0));
  dp[0][0] = 1;

  f(i, 1, n)
    dp[i][0] = 1;

  f(i, 1, n) {
    f(j, 1, k) {
      if(j - arr[i-1] >= 0) {
        dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
      }
      else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  cout<<(dp[n][k] >= 1) ? true : false;
  cout<<endl;
  // cout<<dp[n][k]<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;

  vi arr(n);

  f(i, 0, n-1) {
    cin>>arr[i];
  }

  vvi dp(n+1, vi(k+1, inf));
  // cout<<solve(n, k, arr, dp)<<endl;
  solve2(n, k, arr);

  return 0;
}
