#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define inf 2e18
#define minf -2e18
#define pii pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vi>
#define mid(s, e) (s + (e - s) / 2)
#define all(v) v.begin(), v.end()
#define rep(i, s, e) for(int i = s; i <= e; i++)
#define reprev(i, s, e) for(int i = s; i >= e; i--)
template<typename... T>
void input(T&... args) { ((cin >> args), ...);}
template<typename... T>
void print(T&&... args) { ((cout << args), ...);}
#define debug(x) cout << #x << " = " << x << '\n';
#define bitcount(x) __builtin_popcountll(x)
#define sz size()

int getIndex(vector<pii> &arr, int s, int e, int msb) {
  int m, idx = -1;
  while(s <= e) {
    m = mid(s, e);
    if(msb == arr[m].se) {
      idx = m;
      s = m+1;
    } else {
      e = m-1;
    }
  }

  return idx;
}

int findMSB(int val) {
  int idx = 0;
  val >>= 1;
  while(val) {
    val >>= 1;
    idx++;
  }
 
  return idx;
}

void solve() {
  int n;
  input(n);

  vector<pii> arr(n);
  rep(i, 0, n-1) {
    input(arr[i].fi);
    arr[i].se = findMSB(arr[i].fi);
  }

  sort(all(arr));
  ll ans = 0;

  int j;
  rep(i, 0, n-1) {
    j = getIndex(arr, i+1, n-1, arr[i].se);
    if(j != -1) {
      ans += (j - i);
    }
  }

  print(ans, '\n');
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  ll t = 1;
  cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}