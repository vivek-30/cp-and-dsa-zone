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

vi dp2(100005, inf);

int solve2(int n) {

  if(n <= 0)
    return inf;

  if(n == 1)
    return 0;

  if(dp2[n] != inf)
    return dp2[n];

  int ans = inf, way;
  if(n%3 == 0) {
    way = solve2(n/3);
    ans = min(ans, ((way != inf) ? (way + 1) : way));
  }

  if(n%2 == 0) {
    way = solve2(n/2);
    ans = min(ans, ((way != inf) ? (way + 1) : way));
  }
  
  way = solve2(n-1);
  ans = min(ans, ((way != inf) ? (way + 1) : way));
  
  return dp2[n] = ans;
}

void solve1(int n) {
  
  vi dp(n+1, 0);
  dp[0] = inf;

  f(i, 2, n) {
    dp[i] = inf;
    if(i % 3 == 0) {
      dp[i] = min(dp[i], ((dp[i/3] != inf) ? (1 + dp[i/3]) : inf));
    }

    if(i % 2 == 0) {
      dp[i] = min(dp[i], ((dp[i/2] != inf) ? (1 + dp[i/2]) : inf));
    }

    dp[i] = min(dp[i], 1 + dp[i-1]);
  }

  cout<<dp[n]<<endl;
}

int main() {

  int t;
  cin>>t;

  while(t--) {
    int n;
    cin>>n;

    cout<<solve2(n)<<endl;
    solve1(n);
  }

  return 0;
}
