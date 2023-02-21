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

ll dp[100005];

ll catlan(int n) {
  
  if(n == 0 or n == 1)
    return 1;

  if(dp[n] != -1)
    return dp[n];

  ll ans = 0;
  f(i, 1, n) {
    ans += (catlan(i-1) * catlan(n-i));
  }

  return dp[n] = ans;
}

ll catlan_bottomUp(int n) {
  
  dp[0] = dp[1] = 1;

  f(i, 2, n) {
    dp[i] = 0;
    f(j, 1, i) {
      dp[i] = dp[i] + (dp[j-1] * dp[i-j]);
    }
  }

  return dp[n];
}

int main() {

  int n;
  cin>>n;

  memset(dp, -1, sizeof(dp));

  // f(i, 0, n)
  //   cout<<catlan(i)<<" ";
  
  f(i, 0, n)
    cout<<catlan_bottomUp(i)<<" ";

  cout<<endl;

  return 0;
}
