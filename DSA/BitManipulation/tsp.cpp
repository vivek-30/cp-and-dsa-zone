#include <bits/stdc++.h>
using namespace std;

#define null NULL
#define endl "\n"
#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
#define all(v) v.begin(), v.end()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii > vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vi > vvi;
typedef vector<vll > vvll;
typedef map<int, int> mii;
typedef map<char, int> mci;
template<typename... T>
void inp(T&... args) { ((cin >> args), ...);}
template<typename... T>
void out(T&&... args) { ((cout << args << " "), ...);}
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for(ll i = s; i <= e; i++)
#define fr(i, s, e) for(ll i = s; i >= e; i--)
#define logarr(arr, s, e) for(int i = s; i <= e; i++) cout<<arr[i]<<" "; cout<<endl;
#define bitc(n) __builtin_popcount(n)
#define mp make_pair
#define pb push_back
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define fi first
#define se second
#define INF 2e18

#define N 4

int graph[][N] = { 
  { 0, 20, 42, 25 },
  { 20, 0, 30, 34 },
  { 42, 30, 0, 10 },
  { 25, 34, 10, 0 }};

int dp[20][1<<21];
int start = -1;

int solve(int src, int mask) {

  if(mask == ((1<<N)-1)) {
    return graph[src][start];
  }
  
  if(dp[src][mask] != -1) {
    return dp[src][mask];
  }
  
  int ans = inf;
  f(child, 0, N-1) {
    if(child != src && (mask&(1<<child)) == 0) {
      ans = min(ans, solve(child, (mask | (1<<child))) + graph[src][child]);
    }
  }

  return dp[src][mask] = ans;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp, -1, sizeof(dp));

  start = 0;
  cout<<solve(start, 1)<<endl;

  return 0;
}
