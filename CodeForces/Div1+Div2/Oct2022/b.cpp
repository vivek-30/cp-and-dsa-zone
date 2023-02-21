#include <bits/stdc++.h>
using namespace std;

#define inf 2e18
#define minf -2e18
#define mod 1000000007
#define int long long int
#define ld long double
#define all(v) v.begin(), v.end()
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<char, int> mci;
template<typename... T>
void inp(T&... args) { ((cin >> args), ...);}
template<typename... T>
void out(T&&... args) { ((cout << args), ...);}
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

void solve(int tc) {
  int n;
  inp(n);

  vii arr(n);
  int len_mx = -1, bred_mx = -1;
  f(i, 0, n-1) {
    inp(arr[i].fi, arr[i].se);
    len_mx = max(len_mx, arr[i].fi);
    bred_mx = max(bred_mx, arr[i].se);
  }

  int ans1 = 2*len_mx, ans2 = 2*bred_mx;
  f(i, 0, n-1) {
    if(arr[i].fi <= len_mx && arr[i].se <= len_mx) {
      ans1 += (2*min(arr[i].fi, arr[i].se));
    } else {
      ans1 += (2*max(arr[i].fi, arr[i].se));
    }
  }

  f(i, 0, n-1) {
    if(arr[i].fi <= bred_mx && arr[i].se <= bred_mx) {
      ans2 += (2*min(arr[i].fi, arr[i].se));
    } else {
      ans2 += (2*max(arr[i].fi, arr[i].se));
    }
  }

  out(min(ans1, ans2), br);
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  clock_t begin = clock();

  int tc = 1;
  cin >> tc;

  f(t, 1, tc) {
    solve(t);
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
