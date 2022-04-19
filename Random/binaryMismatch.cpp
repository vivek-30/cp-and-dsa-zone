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
  string s;

  input(n, s);

  if(n&1) {
    no
    return;
  }

  int zero = 0, one = 0;
  for(char ch: s) {
    if(ch == '0') zero++;
    else one++;
  }

  if(one == zero) {
    yes
    print(1, ' ', n, '\n');
    return;
  }

  if(one > zero) {
    rep(i, 0, n-1) s[i] = s[i] == '1' ? '0' : '1';
  }

  map<int, int> m;
  m[0] = 0;

  int curr_sum = 0, target = abs(zero - one)/2;

  rep(i, 0, n-1) {
    if(s[i] == '0') curr_sum++;
    else curr_sum--;

    if(m.count(curr_sum - target)) {
      yes
      print(m[curr_sum - target]+1, ' ', i+1, '\n');
      return;
    }

    m[curr_sum] = i+1;
  }

  no;
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
