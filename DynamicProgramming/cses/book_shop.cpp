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

int solve1(int n, int budget, vi& prices, vi& pages, vvi &dp) {

  if(n <= 0 or budget == 0) return 0;

  if(dp[n][budget] != minf)
    return dp[n][budget];

  if(budget - prices[n-1] >= 0) {
     dp[n][budget] = max(solve1(n-1, budget, prices, pages, dp), solve1(n-1, budget - prices[n-1], prices, pages, dp) + pages[n-1]);  
  } else {
    dp[n][budget] = solve1(n-1, budget, prices, pages, dp);
  }

  return dp[n][budget];
}

void solve2(int n, int budget, vi& prices, vi& pages) {
  
  vvi dp(n+1, vi (budget+1, 0));

  f(i, 1, n) {
    f(j, 1, budget) {
      if(j - prices[i-1] >= 0) {
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-prices[i-1]] + pages[i-1]);
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  cout<<dp[n][budget]<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, budget;
  cin>>n>>budget;

  vi prices(n), pages(n);

  for(int &i: prices)
   cin>>i;

  for(int &i: pages)
   cin>>i;

  vvi dp(n+1, vi(budget+1, minf));

  cout<<solve1(n, budget, prices, pages, dp)<<endl;
  // solve2(n, budget, prices, pages);
  return 0;
}
