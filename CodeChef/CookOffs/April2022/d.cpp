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
#define vi vector<ll>
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

void solve() {
  int n;
  input(n);

  vi arr(n);
  rep(i, 0, n-1) {
    input(arr[i]);
  }

  if(n == 1) {
    print("3\n");
    return;
  }

  map<int, int> m;
  rep(i, 0, n-1) {
    m[arr[i]]++;
  }

  int ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, val;
  for(auto [key, freq]: m) {
    val = freq%4;
    if(val == 0) continue;
    
    if(val == 1) cnt1++;
    else if(val == 2) cnt2++;
    else cnt3++;
  }

  if(cnt1) ans = cnt1;
  if(cnt3) ans += cnt3;

  if((cnt1%2 == 1 && cnt2%2 == 0) or (cnt1%2 == 0 && cnt2%2 == 1)) ans += 2;

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
