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
#define print(x, y) cout << "Case #" << x << ": " << y << "\n";
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for(int i = s; i <= e; i++)
#define fr(i, s, e) for(int i = s; i >= e; i--)
#define logarr(s, e, arr) for(int i = s; i <= e; i++) cout << arr[i] << " ";  cout << "\n";
#define bitc(n) __builtin_popcountll(n)
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

void solve(int tc) {
  int n, x, y;
  inp(n, x, y);

  int sum = 0, total = n*(n+1)/2, rem;

  f(i, 1, (1<<n)-1) {
    sum = 0;
    vi res;
    f(j, 0, 14) {
      if(i&(1<<j)) {
        res.eb(j+1);
        sum += (j+1);
      }
    }
    rem = total - sum;
    f(i, 2, min(sum, rem)) {
      while(sum%i == 0 && rem%i == 0) sum /= i, rem /= i;
    }
    if(sum != total && sum == x && rem == y) {
      print(tc, "POSSIBLE");
      out(res.sz, br);
      for(int val: res) out(val, ' ');
      out(br);
      return;
    }
  }

  print(tc, "IMPOSSIBLE");
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc = 1;
  cin >> tc;

  f(t, 1, tc) {
    solve(t);
  }

  return 0;
}
