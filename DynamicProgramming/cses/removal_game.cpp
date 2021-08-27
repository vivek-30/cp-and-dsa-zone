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

// i => starting index of arr
// j => ending index of arr

ll solve1(int i, int j, int n, vll &arr, vector<vll> &dp) {

  if(i < 0 or j < 0 or i >= n or j >= n or i > j)
    return 0;

  if(dp[i][j] != minf)
    return dp[i][j];

  ll min1 = min(arr[i]+solve1(i+2, j, n, arr, dp), arr[i]+solve1(i+1, j-1, n, arr, dp));
  ll min2 = min(arr[j]+solve1(i+1, j-1, n, arr, dp), arr[j]+solve1(i, j-2, n, arr, dp));

  dp[i][j] = max(min1, min2);
  return dp[i][j]; 
}

void solve2(int n, vll &arr) {
  
  vector<vll > dp(n, vll(n, 0));
  ll  j, x, y, z;
  
  f(len, 1, n) {
    for(int i = 0; i+len <= n; i++) {
      j = i + len - 1;
      x = i+2 <= j ? dp[i+2][j] : 0;
      y = i+1 <= j - 1 ? dp[i+1][j-1] : 0;
      z = i <= j - 2 ? dp[i][j-2] : 0;

      dp[i][j] = max(min(arr[i]+x, arr[i]+y), min(arr[j]+y, arr[j]+z));
    }
  }

  cout<<dp[0][n-1]<<endl;

}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  
  vll arr(n);

  for(ll &i : arr) {
    cin>>i;
  }

  vector<vll> dp(n, vll(n, minf));
  // cout<<solve1(0, n-1, n, arr, dp)<<endl;
  solve2(n, arr);

  return 0;
}
