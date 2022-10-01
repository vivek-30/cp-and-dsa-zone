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

int solve(int &n, vi &arr) {
  vector<ump<int, int> > dp(n);
  if(n == 1)
    return 0;

  int ans = 0;
  int diff = arr[1] - arr[0];
  dp[1][diff] =  1;

  f(i, 2, n-1) {
    fr(j, i-1, 0) {
      diff = arr[i] - arr[j];
      if(dp[j].count(diff)) {
        dp[i][diff] = dp[j][diff] + 1;
        ans += dp[j][diff];
      }
      else {
        dp[i][diff] = 1;
      }
    }
  }

  return ans;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vi v = {4,5,6,1,4,4,2,4,5};
  int n = v.size();
  cout<<solve(n, v)<<endl;

  return 0;
}
