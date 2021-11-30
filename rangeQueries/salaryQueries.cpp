#include <bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define null NULL
#define endl "\n"
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
#define logarr(s, e, arr) for(int i = s; i <= e; i++) cout<<arr[i]<<" "; cout<<endl;
#define bitc(n) __builtin_popcount(n)
#define mp make_pair
#define pb push_back
#define sz size()
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define fi first
#define se second
#define INF 2e18

template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Note -> Usual "s.erase()" function works only if we use this ordered_set as "set" and not as a "multiset".
void custom_erase(ordered_set<int> &s, int val) {
  int order = s.order_of_key(val);
  auto it = s.find_by_order(order);
  s.erase(it);
}

void solve1() {
  
  int n, q;
  inp(n, q);

  int x;

  ordered_set<int> s;
  vi arr(n+1);

  f(i, 1, n) {
    inp(x);
    s.insert(x);
    arr[i] = x;
  }

  while(q--) {
    char qt;
    inp(qt);

    if(qt == '!') {
      int k, x;
      inp(k, x);
      
      custom_erase(s, arr[k]);
      arr[k] = x;
      s.insert(arr[k]);

    } else {
      
      int a, b;
      inp(a, b);

      int st = s.order_of_key(a);
      int ed = s.order_of_key(b+1);

      cout<<(ed - st)<<endl;
    }
  }
  
}

void solve2() {
  int n, q;
  inp(n, q);

  vi arr(n+1);
  mii m;

  f(i, 1, n) {
    inp(arr[i]);
    m[arr[i]]++;
  }

  f(i, 1, q) {
    char qt;
    int x, y;
    inp(qt, x, y);

    if(qt == '!') {
      if(m[arr[x]] > 0) {
        m[arr[x]]--;
      }

      arr[x] = y;
      m[y]++;
    } else {

      int ans = 0;
      auto it = m.lower_bound(x);

      if(it != m.end()) {
        while(it != m.end() && it->fi <= y) {
          ans += it->se;
          it++;
        }
        out(ans, '\n');
      }
    }
  }
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

  solve2();

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
