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
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define fi first
#define se second
#define INF 2e18

void solve1(int n, vector<vector<char> > &grid) {

  vvi dp(n, vi(n, 0));

  dp[n-1][n-1] = grid[n-1][n-1] == '*' ? 0 : 1;

  // for last row
  for(int i=n-2; i>=0; i--) {
    dp[n-1][i] = grid[n-1][i] == '*' ? 0 : dp[n-1][i+1]; 
  }

  // for last col
  for(int i=n-2; i>=0; i--) {
    dp[i][n-1] = grid[i][n-1] == '*' ? 0 : dp[i+1][n-1]; 
  }

  for(int i = n-2; i>=0; i--) {
    for(int j = n-2; j>=0; j--) {
      dp[i][j] = grid[i][j] == '*' ? 0 : (dp[i][j+1] % mod + dp[i+1][j] % mod) % mod;
    }
  }

  cout<<dp[0][0]<<endl;
}

int solve2(vector<vector<char> > &grid, vvi &dp, int n, int row, int col) {

  if(row == n - 1 and col == n - 1 and grid[row][col] != '*')
    return 1;

  if(row >= n or col >= n or grid[row][col] == '*')
    return 0;

  if(dp[row][col] != inf)
    return dp[row][col];

  dp[row][col] = (solve2(grid, dp, n, row+1, col) % mod + solve2(grid, dp, n, row, col+1) % mod) % mod;
  return dp[row][col];
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin>>n;

  vector<vector<char> >  grid(n, vector<char> (n, '.'));

  f(i, 0, n-1)
    f(j, 0, n-1)
      cin>>grid[i][j];

  vvi dp(n, vi(n, inf));

  // cout<<solve2(grid, dp, n, 0, 0)<<endl;
  solve1(n, grid);

  return 0;
}
