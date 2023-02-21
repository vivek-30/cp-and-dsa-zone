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


int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s, t;
  cin>>s>>t;

  int n = s.length(), m = t.length();

  vvi dp(n+1, vi(m+1, 0));
  
  f(i, 1, n) {
    f(j, 1, m) {
      if(s[i-1] == t[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  int len = dp[n][m];
  string ans(len, ' ');

  while(n > 0 and m > 0) {
    if(s[n-1] == t[m-1]) {
      ans[len-1] = s[n-1];
      len--;
      n--;
      m--;
    } else if(dp[n-1][m] > dp[n][m-1]) {
      n--;
    } else {
      m--;
    }
  }

  cout<<ans<<endl;

  return 0;
}
