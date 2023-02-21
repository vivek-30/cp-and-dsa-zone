#include <bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #include "/usr/local/include/c++/10.4.0/ext/pb_ds/assoc_container.hpp"
// #include "/usr/local/include/c++/10.4.0/ext/pb_ds/tree_policy.hpp"
 
using namespace __gnu_pbds;
 
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
  int q;
  inp(q);

  char ch;
  int val;

  int mex = 0, start_idx;
  ordered_set<int> s;
  s.insert(0);

  mii m;

  while(q--) {
    inp(ch, val);

    if(ch == '+') {
      s.insert(val);
    } else {
      while(mex < s.sz && (*s.find_by_order(mex) == mex)) mex++;

      if(!m.count(val)) {
        start_idx = (mex/val)*val;
        if(start_idx < mex) start_idx += val;
      } else {
        start_idx = m[val];
      }
       
      while(s.find(start_idx) != s.end()) start_idx += val;
      m[val] = start_idx;

      out(start_idx, br);
    }
  }
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
  // cin >> tc;

  f(t, 1, tc) {
    solve(t);
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
