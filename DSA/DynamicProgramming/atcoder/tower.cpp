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

class Block {
  public:
    ll w, s, v;
};

bool cmp(Block &a, Block &b) {
  return (a.s + a.w) > (b.s + b.w);
}

void solve(ll n, vector<Block> &arr) {
  
  sort(arr.begin(), arr.end(), cmp);
  vvll dp(n, vll(10005, 0));

  f(i, 0, 10002) {
    if(arr[0].s >= i) {
      dp[0][i] = arr[0].v;
    }
  }

  f(i, 1, n-1) {
    f(j, 0, 10002) {
      dp[i][j] = dp[i-1][j];
      ll val = (arr[i].w + j) <= 10002 ? dp[i-1][arr[i].w + j] : 0;
      dp[i][j] = max(dp[i][j], ((arr[i].s >= j) ? val + arr[i].v : 0));
    }
  } 

  cout<<dp[n-1][0]<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  vector<Block> arr(n);

  f(i, 0, n-1)
    cin>>arr[i].w>>arr[i].s>>arr[i].v;

  solve(n, arr);

  return 0;
}
