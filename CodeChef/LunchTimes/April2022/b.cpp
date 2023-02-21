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
  int x, y;
  input(x, y);

  if(x&1 && y&1) {
    print("-1\n");
    return;
  } 

  string s1 = "", s2 = "";
  if(x&1) {
    s1 = "a";
    rep(i, 1, (x-1)/2)  {
      s1 += "a";
      s1 = "a" + s1;
    }

    rep(i, 1, y/2) {
      s1 += "b";
      s1 = "b" + s1;
    }

    s2 = "a";
    rep(i, 1, y/2)  {
      s2 += "b";
      s2 = "b" + s2;
    }

    rep(i, 1, (x-1)/2) {
      s2 += "a";
      s2 = "a" + s2;
    }
  } else if(y&1) {
    s2 = "b";
    rep(i, 1, (y-1)/2)  {
      s2 += "b";
      s2 = "b" + s2;
    }

    rep(i, 1, x/2) {
      s2 += "a";
      s2 = "a" + s2;
    }

    s1 = "b";
    rep(i, 1, (x)/2)  {
      s1 += "a";
      s1 = "a" + s1;
    }

    rep(i, 1, (y-1)/2) {
      s1 += "b";
      s1 = "b" + s1;
    }
  } else {
    rep(i, 1, x/2)  {
      s2 += "a";
      s2 = "a" + s2;
    }

    rep(i, 1, y/2) {
      s2 += "b";
      s2 = "b" + s2;
    }

    rep(i, 1, y/2)  {
      s1 += "b";
      s1 = "b" + s1;
    }

    rep(i, 1, x/2) {
      s1 += "a";
      s1 = "a" + s1;
    }
  }

  if(s1 == s2) {
    print("-1\n");
    return;
  }

  print(s1, '\n', s2, '\n');
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
