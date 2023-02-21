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

ll dp[22][(1 << 22)];   // 22 * 2^22

ll solve(int i, int n, int mask, vector<vector<bool> > &arr) {
  
  if(i == n+1) {
    return mask == 0 ? 1 : 0;
  }  

  if(dp[i][mask] != -1)
    return dp[i][mask];

  ll ans = 0;
  f(j, 1, n) {
    if((mask & (1 << (j-1) )) and arr[i][j]) {
      ans = (ans % mod + solve(i+1, n, (mask & ( ~ (1 << (j-1)))), arr) % mod) % mod;
    }
  }

  return dp[i][mask] = ans;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x, mask;
  cin>>n;

  vector<vector<bool> > arr(n+1, vector<bool>(n+1, false));
  f(i, 1, n) {
    f(j, 1, n) {
      cin>>x;
      arr[i][j] = (x == 1) ? true : false;
    }
  }

  mask = (1 << n) - 1;  // all the bits are set bits of a (2^n - 1) number
  memset(dp, -1, sizeof(dp));
  
  cout<<solve(1, n, mask, arr)<<endl;

  return 0;
}
