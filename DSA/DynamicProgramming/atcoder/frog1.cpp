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

int solve1(int n, vi &arr, vi &dp) {

  if(n <= 0)
    return inf;

  if(n == 1)
    return 0;

  if(dp[n] != inf)
    return dp[n];

  int w1 = solve1(n-1, arr, dp) + abs(arr[n-1] - arr[n-2]);
  int w2 = inf;
  if(n-2 >= 1)
    w2 = solve1(n-2, arr, dp) + abs(arr[n-1] - arr[n-3]);

  return dp[n] = min(w1, w2);
}

void solve2(int n, vi &arr) {
  
  vi dp(n, inf);
  dp[0] = 0;

  f(i, 1, n) {
    if(i - 2 >= 0)
     dp[i] = min(dp[i-1] + abs(arr[i] - arr[i-1]), dp[i-2] + abs(arr[i] - arr[i-2]));
    else dp[i] = dp[i-1] + abs(arr[i] - arr[i-1]);
  }

  cout<<dp[n-1]<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

    int n;
    cin>>n;

    vi arr(n);
    f(i, 0, n-1)
      cin>>arr[i];

    vi dp(n+1, inf);
    cout<<solve1(n, arr, dp)<<endl;
    // solve2(n, arr);

  return 0;
}
