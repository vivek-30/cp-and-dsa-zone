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
#define yes cout << "YES" << "\n";
#define no cout << "NO" << "\n";
#define pii pair<ll, ll>
#define vi vector<int>
#define vii vector<pii>
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

int m;

int cal(int x, int y) {
  return max((x + y + (y - x + m) % m), (x + y + (x - y + m) % m));
}

void solve() {
  int n;
  input(n, m);

  vi arr(n);
  rep(i, 0, n-1) {
    input(arr[i]);
  }

  int mx = INT_MIN;

  sort(all(arr));
  int i = n-2;

  while(i >= 0 && arr[i] == arr[n-1]) {
    i--;
  }

  if(i < 0) {
    print(arr[n-1] + arr[n-2], '\n');
    return;
  }

  int mxx = arr[n-1]+arr[n-1];
  mxx = max(mxx, cal(arr[i], arr[n-1]));
  rep(i, 0, n-2) {
    mxx = max(mxx, cal(arr[i], arr[n-1]));
  }

  rep(i, 1, n-1) {
    mxx = max(mxx, cal(arr[0], arr[i]));
  }

  print(mxx, '\n');
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int t = 1;
  cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}
