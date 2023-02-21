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
#define vvi vector<vll>
#define mid(s, e) (s + (e - s) / 2)
#define all(v) v.begin(), v.end()
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define reprev(i, s, e) for(ll i = s; i >= e; i--)
template<typename... T>
void input(T&... args) { ((cin >> args), ...);}
template<typename... T>
void print(T&&... args) { ((cout << args), ...);}
#define debug(x) cout << #x << " = " << x << '\n';
#define bitcount(x) __builtin_popcountll(x)
#define sz size()

void solve() {
  int n, k;
  input(n, k);

  vi arr(n);
  rep(i, 0, n-1) input(arr[i]);

  sort(all(arr));

  int ans = 0;
  bool flag = true;
  
  rep(i, 0, n-1) {
    if(arr[i] <= k) {
      ans++;
      k -= arr[i];
    }
    else {
      if((arr[i]%2 == 1) and ((arr[i]/2 + 1) <= k) and flag) {
        ans++;
        k -= (arr[i]/2 + 1); 
        flag = false;
      } else if((arr[i]%2 == 0) and ((arr[i]/2) <= k) and flag){
        ans++;
        k -= (arr[i]/2); 
        flag = false;
      }
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