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

void solve2(int tc) {
  int n;
  inp(n);

  if(n <= 3) {
    f(i, 1, n) out(i, ' ');
    out(br);
    return; 
  }

  if(n&1) {
    int val1 = n/2, i = 1, val2;
    while(i <= n) {
      out(i, ' ');
      i += val1;
    }

    val1 = n - val1 - 1, val2 = n - 1;
    while(val1 > 1) {
      out(val1, ' ', val2, ' ');
      val1--, val2--;
    }
  } else {
    out(n/2, ' ', n, ' ');
    int val1 = n/2 - 1, val2 = n - 1;
    while(val1 > 0) {
      out(val1, ' ', val2, ' ');
      val1--, val2--;
    }
  }

  out(br);
}

void solve(int tc) {
  int n;
  inp(n);

  if(n <= 3) {
    f(i, 1, n) out(i, ' ');
    out(br);
    return; 
  }

  vi arr(n);
  f(i, 1, n) arr[i-1] = i;

  vi res;
  int mn = inf, mx = minf;
  do{
    mn = inf;
    f(i, 1, n-1) {
      mn = min(mn, abs(arr[i] - arr[i-1]));
    }
    if(mx < mn) {
      res = arr;
      mx = mn;
    }
  } while (next_permutation(all(arr)));

  logarr(0, n-1, res);
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
    solve2(t);
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
