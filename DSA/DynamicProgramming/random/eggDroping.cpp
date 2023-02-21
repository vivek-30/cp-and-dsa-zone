#include<bits/stdc++.h>
using namespace std;

#define null NULL
#define inf INT_MAX
#define minf INT_MIN
#define ll long long int
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define vi vector<int>
#define mii map<int, int>
#define vvi vector<vector<int> >
#define pii pair<int, int>
#define mid(l, r) (l + (r - l) / 2)
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define f(i,s,n) for(ll i = s; i <= n; i++)
#define fr(i,s,e) for(ll i = s; i >= e; i--)

ll dp[100005][105];

ll solve1(ll n, ll k) {
  
  if(k == 0)
    return 0;
  
  if(n == 0 or n == 1)
    return n;

  if(dp[n][k] != -1)
    return dp[n][k];

  if(k == 1)
    return n;

  ll ans = inf;
  f(x, 1, n) {
    ans = min(ans, 1 + max(solve1(x-1, k-1), solve1(n-x, k)));
  }

  return dp[n][k] = ans;
}

void solve2(ll n, ll k) {
  vector<vector<ll> > dp(n+1, vector<ll>(k+1, 0));
  
  f(i, 1, n) {
    dp[i][1] = i;
  }

  f(i, 1, k) {
    dp[1][i] = 1;
  }

  f(i, 2, n) {
    f(j, 2, k) {
      dp[i][j] = inf;
      f(x, 1, i) {
        dp[i][j] = min(dp[i][j], 1 + max(dp[x-1][j-1], dp[i-x][j]));
      }
    }
  }

  cout<<dp[n][k]<<endl;
}

int main() {

  int t;
  cin>>t;

  memset(dp, -1, sizeof(dp));

  while(t--) {
    ll k, n;
    cin>>k>>n;

    cout<<solve1(n, k)<<endl;
    solve2(n, k);
  }

  return 0;
}
