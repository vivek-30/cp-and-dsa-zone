#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
#define ld long double
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
void out(T&&... args) { ((cout << args), ...);}
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for(ll i = s; i <= e; i++)
#define fr(i, s, e) for(ll i = s; i >= e; i--)
#define logarr(s, e, arr) for(int i = s; i <= e; i++) cout << arr[i] << " ";  cout << "\n";
#define bitc(n) __builtin_popcount(n)
#define debug(x) cout << #x << " = " << x << "\n";
#define mp make_pair
#define eb emplace_back
#define sz size()
#define br "\n"
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define py cout << "YES" << "\n";
#define pn cout << "NO" << "\n";
#define fi first
#define se second
#define INF 2e18

void solve() {
  ll hc, dc;
  inp(hc, dc);

  ll hm, dm;
  inp(hm, dm);

  ll k, att, hel;
  inp(k, att, hel);

  ll x = hm%dc == 0 ? hm/dc : hm/dc+1;
  ll y = hc%dm == 0 ? hc/dm : hc/dm+1;

  if(x <= y) {
    py
    return;
  }
  
  if(k == 0) {
    pn
    return;
  }

  bool isPossible = false;

  ll th, td, tx, ty, j;

  f(i, 0, k) {
    j = (k - i);
    th = hc + i*hel;
    td = dc + j*att;
    tx = th%dm == 0 ? th/dm : th/dm+1;
    ty= hm%td == 0 ? hm/td : hm/td+1;

    if(ty <= tx) {
      isPossible = true;
      break;
    }
  }

  if(isPossible) py
  else pn
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

  int t;
  cin >> t;

  while(t--) {
    solve();
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
