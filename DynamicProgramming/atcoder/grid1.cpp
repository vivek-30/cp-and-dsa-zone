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

void solve() {

}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int r, c;
  cin >> r >> c;

  vector<vector<char> > grid(r, vector<char> (c, '.'));
  f(i, 0, r-1)
    f(j, 0, c-1)
      cin>>grid[i][j];

  vvll dp(r, vll(c, 0));
  dp[r-1][c-1] = 1;

  fr(i, r-2, 0) {
    if(grid[i][c-1] == '#')
      dp[i][c-1] = 0;
    else dp[i][c-1] = dp[i+1][c-1];
  }

  fr(i, c-2, 0) {
    if(grid[r-1][i] == '#')
      dp[r-1][i] = 0;
    else dp[r-1][i] = dp[r-1][i+1];
  }

  fr(i, r-2, 0) {
    fr(j, c-2, 0) {
      if(grid[i][j] == '#')
        dp[i][j] = 0;
      else dp[i][j] = (dp[i+1][j] % mod + dp[i][j+1] % mod) % mod;
    }
  }

  cout<<dp[0][0]<<endl;

  return 0;
}
