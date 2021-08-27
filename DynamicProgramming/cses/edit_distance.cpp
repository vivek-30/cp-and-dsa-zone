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

void solve1(string &s1, string &s2, int n, int m) {

  vvi dp(n+1, vi(m+1, 0));
  
  dp[0][0] = 0; // both are empty strings so requries 0 opertions for making them equal
  
  f(i, 1, n) {
    dp[i][0] = i; // 1st str has length [i, n] and 2nd has 0 so required i operations
  }

  f(i, 1, m) {
    dp[0][i] = i; // // 1st str has 0 length and 2nd str has length [i, m] so required i operations
  }

  f(i, 1, n) {
    f(j, 1, m) {
      if(s1[i-1] == s2[j-1]) {
        dp[i][j] = dp[i-1][j-1];
      } else {
        dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
      }
    }
  }

  cout<<dp[n][m]<<endl;
}

int solve2(string &s1, string &s2, int n, int m, vvi &dp) {

  if(n == 0 and m == 0)
    return 0;

  if((n == 0 and m > 0) or (m == 0 and n > 0))
    return n == 0 ? m : n;

  if(n < 0 or m < 0) return 0;

  if(dp[n][m] != -1)
    return dp[n][m];
  
  if(s1[n-1] == s2[m-1])
    dp[n][m] = solve2(s1, s2, n-1, m-1, dp);
  else  {
    dp[n][m] = 1 + min(solve2(s1, s2, n-1, m-1, dp), min(solve2(s1, s2, n, m-1, dp), solve2(s1, s2, n-1, m, dp)));
  }               // for replacing      // for adding a char to shorter string    for removing a char from longer string

  return dp[n][m]; 
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s1, s2;
  cin>>s1>>s2;

  int n = s1.length(), m = s2.length();
  vvi dp(n+1, vi(m+1, -1));

  // cout<<solve2(s1, s2, n, m, dp)<<endl;
  solve1(s1, s2, n, m);

  return 0;
}
