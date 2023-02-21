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

int solve1(int l, int b, vvi &dp) {

  if(l <= 0 or b <= 0)
    return 0;

  if(l == b)
    return 0;

  if(dp[l][b] != inf)
    return dp[l][b];

  // Vertical cuts
  f(i, 1, l-1) {
    dp[l][b] = min(dp[l][b], 1 + solve1(i, b, dp) + solve1(l-i, b, dp));
  }

  // Horizontal cuts
  f(i, 1, b-1) {
    dp[l][b] = min(dp[l][b], 1 + solve1(l, i, dp) + solve1(l, b-i, dp));
  }

  return dp[l][b];
}

void solve2(int l, int b) {
    vvi dp(l+1, vi(b+1, inf));

    f(i, 1, l) {
      f(j, 1, b) {
        if(i == j) {
          dp[i][j] = dp[i-1][j-1] == inf ? 0 : dp[i-1][j-1];
        }
        else {
          // Vertical cuts
          f(k, 1, i-1) {
            dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
          }

          // Horizontal cuts
          f(k, 1, j-1) {
            dp[i][j]  = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
          } 
        }
      }
    }

    cout<<dp[l][b]<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int l, b;
  cin>>l>>b;

  vvi dp(l+1, vi(b+1, inf));

  // cout<<solve1(l, b, dp)<<endl;
  solve2(l, b);

  return 0;
}
