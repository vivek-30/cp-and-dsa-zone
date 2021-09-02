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

int solve2(int i, int j, string &s, vvi &dp) {
  if(i > j)
    return 0;

  if(i == j)
    return 1;

  if(dp[i][j] != -1) {
    return dp[i][j];
  }

  if(s[i] == s[j]) {
    dp[i][j] = 2 + solve2(i+1, j-1, s, dp);
  } else {
    dp[i][j] = max(solve2(i+1, j, s, dp), solve2(i, j-1, s, dp));
  }

  return dp[i][j];
}

void solve(string &s, int &n) {
  
  if(n == 1) {
    cout<<1<<endl;
    return;
  }

  vvi dp(n+1, vi(n+1, 0));

  f(i, 1, n) {
    dp[i][i] = 1;
  }
  
  ll j = 0;
  f(len, 2, n) {
    for(ll i = 0; i <= n - len; i++) {
      j = i + len - 1;

      if(i != j) {
        if(s[i] == s[j]) {
          dp[i][j] = 2 + dp[i+1][j-1];
        }
        else {
          dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
      }
    }
  }

  cout<<dp[0][n-1]<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  cin>>s;

  int n = s.length();

  vvi dp(n, vi(n, -1));

  solve(s, n);
  // cout<<solve2(0, n-1, s, dp)<<endl;

  return 0;
}
