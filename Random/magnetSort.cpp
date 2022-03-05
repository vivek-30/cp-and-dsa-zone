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
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for(ll i = s; i <= e; i++)
#define fr(i, s, e) for(ll i = s; i >= e; i--)
#define logarr(s, e, arr) for(int i = s; i <= e; i++) cout << arr[i] << " ";  cout << "\n";
#define bitc(n) __builtin_popcount(n)
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

bool check(int s, int e, vi arr) {
  sort(arr.begin()+s, arr.begin()+e+1);
  return is_sorted(all(arr));
}

void solve() {
  int n;
  inp(n);

  string s;
  vi arr(n);
  for(int &i: arr) inp(i);

  inp(s);

  if(is_sorted(all(arr))) {
    out("0\n");
    return;
  }

  int cnt_n = 0;
  f(i, 0, n-1) cnt_n += (s[i] == 'N');

  if(cnt_n == 0 or cnt_n == n) {
    out("-1\n");
    return;
  }

  int first_n = -1, last_n = -1, first_s = -1, last_s = -1;
  f(i, 0, n-1) {
    if(s[i] == 'N') {
      if(first_n == -1) first_n = i;
      last_n = i;
    }
    else {
      if(first_s == -1) first_s = i;
      last_s = i;
    }
  }

  if(check(first_n, last_s, arr) or check(first_s, last_n, arr) or s[0] != s[n-1]) {
    out("1\n");
  } else out("2\n");
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  clock_t begin = clock();

  int t;
  cin >> t;

  while(t--) {
    solve();
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
