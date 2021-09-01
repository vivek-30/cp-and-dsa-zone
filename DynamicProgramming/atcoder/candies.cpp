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

void solve(ll n, ll k, vll &arr, vvll &dp) {

  f(i, 0, k) {
    if(arr[1] >= i) {
      dp[1][i] = 1;
    }
  }

  f(i, 2, n) {
    f(j, 0, k) {
      if(j == 0) {
        dp[i][j] = dp[i-1][j];
      } else {
      dp[i][j] = (mod + dp[i][j-1] % mod + dp[i-1][j] % mod - ((j-arr[i]-1 >= 0) ? dp[i-1][j-arr[i]-1] : 0) % mod) % mod;
      }
    }
  }

  cout<<dp[n][k]<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n, k;
  cin>>n>>k;

  vll arr(n+1);

  f(i, 1, n)
    cin>>arr[i];

  vvll dp(n+1, vll(k+1, 0));
  solve(n, k, arr, dp);

  return 0;
}
