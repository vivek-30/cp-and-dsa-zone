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

void solve(int n, vll & height, vll &beauty) {

  vll dp(n+1, 0);
  map<ll, ll> m;
  
  dp[1] = beauty[1];
  m[height[1]] = beauty[1];
  ll ans = dp[1];

  f(i, 2, n) {
    dp[i] = beauty[i];
    auto it = m.lower_bound(height[i] + 1);

    if(it != m.begin()) {
      it--;
      dp[i] = dp[i] + it->second;
    }
    m[height[i]] = dp[i];

    it = m.upper_bound(height[i]);

    while(it != m.end() and it->second <= dp[i]) {
      auto temp = it;
      temp++;
      m.erase(it);
      it = temp;
    }
  
    ans = max(ans, dp[i]);
  }

  cout<<ans<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vll height(n+1), beauty(n+1);

  f(i, 1, n) {
    cin>>height[i];
  }

  f(i, 1, n) {
    cin>>beauty[i];
  }

  solve(n, height, beauty);

  return 0;
}
