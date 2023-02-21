#include <bits/stdc++.h>
using namespace std;

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

#define Left (2 * idx)
#define Right (2 * idx + 1)

vii tree;
vi arr;

void build(int idx, int s, int e) {

  if(s == e) {
    tree[idx].fi = arr[s];
    tree[idx].se = 1;
    return;
  }

  int m = mid(s, e);
  build(Left, s, m);
  build(Right, m+1, e);

  tree[idx].fi = min(tree[Left].fi, tree[Right].fi);
  tree[idx].se = tree[idx].fi == tree[Left].fi ? tree[Left].se : 0;
  tree[idx].se += tree[idx].fi == tree[Right].fi ? tree[Right].se : 0;
  
}

void update(int idx, int s, int e, int pos, int val) {
  if(s == e) {
    tree[idx].fi = arr[pos] = val;
    return;
  }

  int m = mid(s, e);
  if(pos > m) {
    update(Right, m+1, e, pos, val);
  } else {
    update(Left, s, m, pos, val);
  }

  tree[idx].fi = min(tree[Left].fi, tree[Right].fi);
  tree[idx].se = tree[idx].fi == tree[Left].fi ? tree[Left].se : 0;
  tree[idx].se += tree[idx].fi == tree[Right].fi ? tree[Right].se : 0;
}

pii query(int idx, int s, int e, int qs, int qe) {
  if(e < qs or s > qe) return {inf, 0};

  if(s >= qs && e <= qe) return tree[idx];

  int m = mid(s, e);

  pii res = {0, 0};

  pii left = query(Left, s, m, qs, qe);
  pii right = query(Right, m+1, e, qs, qe);

  res.fi = min(left.fi, right.fi);
  res.se += left.fi == res.fi ? left.se : 0;
  res.se += right.fi == res.fi ? right.se : 0;

  return res;
}

void solve() {
  int n, m;
  inp(n, m);

  arr.resize(n + 1);
  tree.resize(4*n);
  f(i, 1, n) inp(arr[i]);

  while(m--) {
    int qt;
    inp(qt);

    if(qt == 1) {
      int pos, val;
      inp(pos, val);

      update(1, 1, n, pos, val);
    } else {
      int l, r;
      inp(l, r);

      pii res = query(1, 1, n, l+1, r);
      out(res.fi, " ", res.se, '\n');
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

  solve();

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
