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
  int n, x;
  input(n, x);

  if(3*n >= x) {
    int num = 0, a = 0, b = 0, c = 0, s = 0 , e = n, m, res;
    while(s <= e) {
      m = mid(s, e);
      if(3*m == x) {
        res = m;
        break;
      } else if(3*m > x) {
        res = m;
        e = m-1;
      } else {
        s = m+1;
      }
    }

    num = 3*res;
    a = res;

    if(num == x) {
      print("YES\n");
      c = n - a;
      print(a, ' ', b, ' ', c, '\n');
    } else {
      b += (num - x);
      if(a + b > n) {
        print("NO\n");
        return;
      } else {
        print("YES\n");
        c = n - (a+b);
        print(a, ' ', b, ' ', c, '\n');
      }
    }
  } else {
    print("NO\n");
  }
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