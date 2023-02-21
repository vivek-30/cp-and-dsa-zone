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

void solve() {
  int n;
  inp(n);

  vi arr(n), res(n);
  f(i, 0, n-1) inp(arr[i]);

  // Rotate Function Usage -

  // For left Rotate
  // rotate(arr.begin()+start, arr.begin()+start+times, arr.begin()+start+length+1);
  // for normal rotate use start as 0

  // For Right Rotate
  // rotate(arr.begin()+start, arr.begin()+start+n - times, arr.begin()+start+length+1);
  // for normal rotate use start as 0

  fr(i, n-1, 0) {
    if(arr[i] == (i+1)) {
      res[i] = 0;
    } else {
      int pos = find(all(arr), (i + 1)) - arr.begin();
      res[i] = (pos + 1) % (i + 1);

      rotate(arr.begin(), arr.begin() + res[i], arr.begin() + i + 1);
    }
  }

  logarr(0, n-1, res);
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

  int t = 1;
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
