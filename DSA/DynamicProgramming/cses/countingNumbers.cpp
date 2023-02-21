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
#define sz size()
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define fi first
#define se second
#define INF 2e18

ll dp[20][10][2][2];

ll getAns(string s, int pos, int prev, int trailing_zeros, int bound) {

  if(pos == s.sz) return 1;

  if(dp[pos][prev][trailing_zeros][bound] != -1) {
    return dp[pos][prev][trailing_zeros][bound];
  }

  int ub = bound ? s[pos] - '0' : 9;
  ll ans = 0;

  f(i, 0, ub) {
    if(i == prev && trailing_zeros == 0) continue;
    ans += getAns(s, pos+1, i, (trailing_zeros & (i == 0)), (bound & (i == ub)));
  }

  return dp[pos][prev][trailing_zeros][bound] = ans;
}

void solve() {
  
  ll a, b;
  inp(a, b);

  memset(dp, -1, sizeof(dp));
  ll ans2 = getAns(to_string(b), 0, 0, 1, 1);

  ll ans1 = 0;

  if(a > 0) {
    a--;
    memset(dp, -1, sizeof(dp));
    ans1 = getAns(to_string(a), 0, 0, 1, 1);
  }

  cout<<(ans2 - ans1)<<endl;
}


int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  clock_t begin = clock();

  solve();

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
