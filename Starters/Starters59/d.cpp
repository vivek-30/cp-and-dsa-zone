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
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define reprev(i, s, e) for(int i = s; i >= e; i--)
template<typename... T>
void input(T&... args) { ((cin >> args), ...);}
template<typename... T>
void print(T&&... args) { ((cout << args), ...);}
#define debug(x) cout << #x << " = " << x << '\n';
#define bitcount(x) __builtin_popcountll(x)
#define sz size()

void solve() {
  ll n, m;
  
  input(n);
  vi a(n);
  
  for(ll &i: a) input(i);
  input(m);
  vi b(m);
  
  for(ll &i: b) input(i);
  
  ll ans = minf, curr = 0;
  deque<ll> d1, d2;
  for(ll val: a) d1.pb(val), d2.pb(val);
  
  rep(i, 0, m-1) {
    if(b[i] < 0) {
        d1.pb(b[i]);
        d2.push_front(b[i]);
    } else {
        d1.push_front(b[i]);
        d2.pb(b[i]);
    }
  }
  
  vi arr1, arr2;
  for(ll val: d1) arr1.pb(val);
  for(ll val: d2) arr2.pb(val);
  
  for(ll val: arr1) {
      curr += val;
      ans = max(curr, ans);
      
      curr = max(curr, (ll)0);
  }
  
  curr = 0;
   for(ll val: arr2) {
      curr += val;
     ans = max(curr, ans);
      
      curr = max(curr, (ll)0);
  }
  
  
  curr = 0;
   rep(i, arr1.sz-1, 0) {
      curr += arr1[i];
     ans = max(curr, ans);
      
      curr = max(curr, (ll)0);
  }
  
curr = 0;
   rep(i, arr2.sz-1, 0) {
      curr += arr2[i];
     ans = max(curr, ans);
      
      curr = max(curr, (ll)0);
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

  int t = 1;
  cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}
