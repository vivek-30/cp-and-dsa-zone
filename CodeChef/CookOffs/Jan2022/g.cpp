#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
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

  vi arr(n);
  int mx = minf, pos = -1;
  f(i, 0, n-1) {
    inp(arr[i]);
    if(arr[i] > mx) {
      mx = arr[i];
      pos = i;
    }
  }

  if(pos == 0)  {
    pn
    return;
  }

  if(pos == n-1) {
    py
    return;
  }

  vb hasSmaller(n, false), hasLarger(n, false);
  f(i, 0, n-1) {
    fr(j, i-1, 0) {
      if(arr[j] < arr[i]) {
        hasSmaller[i] = true;
        break;
      }
    }

    f(j, i+1, n-1) {
      if(arr[j] > arr[i]) {
        hasLarger[i] = true;
        break;
      }
    }
  }

  bool flag = true;
  f(i, pos+1, n-1) {
    if(!hasLarger[i] && !hasSmaller[i]) {
      flag = false;
      break;
    }
  }

  if(flag) py
  else pn
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
