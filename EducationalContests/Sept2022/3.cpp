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

// void remove_identical_elements(vi &a, vi &b) {
//   map<ll, ll> m1, m2;
//   for(auto &val: a) m1[val]++;
//   for(auto &val: b) m2[val]++;
  
//   for(auto &val: b) if(m1.count(val)) m1[val]--, m2[val]--;
//   for(auto [key, val]: m1) if(val > 0 && m2.count(key)) m2[key]--, m1[key]--;

//   a.clear();
//   b.clear();

//   for(auto [key, val]: m1) {
//     f(i, 1, val) a.eb(key);
//   }

//   for(auto [key, val]: m2) {
//     f(i, 1, val) b.eb(key);
//   }
// }

void solve(int tc) {
  int n;
  inp(n);

  vi a(n), b(n);

  for(int &i: a) inp(i);
  for(int &i: b) inp(i);

  int cnt = 0;

  pqmax aa(all(a)), bb(all(b));
  while(aa.sz) {
    if(aa.top() == bb.top()) {
      aa.pop();
      bb.pop();
      cnt--;
    } else if(aa.top() > bb.top()) {
      int top = aa.top();
      aa.pop();
      aa.push(log10(top)+1);
    }
    else {
      int top = bb.top();
      bb.pop();
      bb.push(log10(top)+1);
    }
    cnt++;
  }

  out(cnt, br);
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
