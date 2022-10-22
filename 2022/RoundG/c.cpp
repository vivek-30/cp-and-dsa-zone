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
  int n;
  inp(n);

  vi arr(n+1);
  vll prefix(n+1, 0);
  f(i, 1, n) {
    inp(arr[i]);
    prefix[i] = arr[i] + prefix[i-1];
  }

  ll prev = 1, curr = 0, ans = 0;
  f(i, 1, n) {
    curr += arr[i];
    if(curr < 0) {
      curr = 0;
      f(j, prev, i-1) {
        f(k, j, i-1) {
          curr = (prefix[k] - prefix[j-1]);
          if(curr < 0) break;;
          ans += curr;
        }
      }
      prev = i+1;
    }
  }

  f(j, prev, n) {
    f(k, j, n) {
      curr = (prefix[k] - prefix[j-1]);
      if(curr < 0) break;
      ans += curr;
    }
  }

  print(tc, ans);
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
