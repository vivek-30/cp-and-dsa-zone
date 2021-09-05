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

ll dp[100005][105][2];

ll solve(string &K, ll &D, int pos, int d, int c) {
  
  if(dp[pos][d][c] != -1)
    return dp[pos][d][c];

  int ub = c ? (K[pos] - '0') : 9;
  ll ans = 0;

  // Base Case
  if(pos == K.size()-1) {
    f(x, 0, ub) {
      if(x % D == d) {
        ans++;
      }
    }
    return ans;
  }

  f(x, 0, ub) {
    ans = (ans % mod + solve(K, D, pos+1, ((D + d - x%D) % D), (c && (x == ub))) % mod) % mod;
  }

  return dp[pos][d][c] = ans;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string K;
  ll D;
  cin>>K;
  cin>>D;

  memset(dp, -1, sizeof(dp));

  cout<<((mod + solve(K, D, 0, 0, 1) - 1)%mod)<<endl;

  return 0;
}
