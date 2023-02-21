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

ll dp[1<<17];
ll sum[1<<17];

ll compute(int n, int subset, vvll &arr) {
  
  ll ans = 0;
  
  f(i, 0, n-1) {
    f(j, i+1, n-1) {
      if(subset&(1<<i) and subset&(1<<j)) {
        ans += arr[i][j];
      }
    }
  }

  return ans;
}

ll solve(int mask, vvll &arr) {
  if(mask == 0)
    return 0;

  if(dp[mask] != -1)
    return dp[mask];

  ll ans = minf;
  for(int submask = mask; submask != 0; submask = (submask-1)&mask) {
    ans = max(ans, sum[submask] + solve((mask ^ submask), arr));
  }

  return dp[mask] = ans;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vvll arr(n, vll(n, 0));
  
  f(i, 0, n-1) {
    f(j, 0, n-1) {
      cin>>arr[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));
  memset(sum, 0, sizeof(sum));

  f(subset, 1, (1<<17)-1) {
    sum[subset] = compute(n, subset, arr);
  }

  cout<<solve(((1<<n)-1), arr)<<endl;

  return 0;
}
