#include <bits/stdc++.h>
using namespace std;

// Ordered Set/Multiset
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

// For MultiSet Just Relpace Tag "less" With "less_equal".
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
#define logarr(arr, s, e) for(int i = s; i <= e; i++) cout<<arr[i]<<" "; cout<<endl;
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

void solve1() {
  
  int n, x;
  inp(n);

  ordered_set<int> s;
  vi arr(n+1);
  
  f(i, 1, n) {
    inp(arr[i]);
    s.insert(i);
  }

  f(i, 1, n) {
    inp(x);
    auto it = s.find_by_order(x-1); // Bcoz Of 0 based Indexing Of Ordered Set
    cout<<arr[(*it)]<<" ";
    s.erase(it);
  }

  cout<<endl;
}

void build(int idx, int s, int e, vi &tree) {
  if(s == e) {
    tree[idx] = 1;
    return;
  }

  int m = mid(s, e);
  build(2*idx, s, m, tree);
  build(2*idx+1, m+1, e, tree);

  tree[idx] = tree[2*idx] + tree[2*idx+1];
}

int query(int idx, int s, int e, int x, vi &arr, vi &tree) {
  
  if(s == e) {
    tree[idx] = 0;
    return arr[s];
  }

  int m = mid(s, e);
  int ans;

  if(tree[2*idx] >= x) {
    ans = query(2*idx, s, m, x, arr, tree);
  } else {
    ans = query(2*idx+1, m+1, e, x - tree[2*idx], arr, tree);
  }

  tree[idx] = tree[2*idx] + tree[2*idx+1];
  return ans;
}

void solve2() {
  
  int n, x;
  inp(n);

  vi arr(n+1), tree(4*n);
  f(i, 1, n) {
    inp(arr[i]);
  }

  build(1, 1, n, tree);

  f(i, 1, n) {
    inp(x);
    out(query(1, 1, n, x, arr, tree), " ");
  }

  cout<<endl;
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
