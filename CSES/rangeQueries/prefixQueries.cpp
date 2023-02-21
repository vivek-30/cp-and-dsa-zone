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

struct Data {
  ll prefix, sum;
  Data() {
    prefix = sum = 0;
  }
};

vi arr;
vector<Data> tree;

void build(int idx, int s, int e) {

  if(s == e) {
    tree[idx].sum = arr[s];
    tree[idx].prefix = max(0, arr[s]);
    return;
  }

  int m = mid(s, e);
  build(Left, s, m);
  build(Right, m+1, e);

  tree[idx].sum = tree[Left].sum + tree[Right].sum;
  tree[idx].prefix = max(tree[Left].prefix, tree[Left].sum + tree[Right].prefix);
}

void update(int idx, int s, int e, int pos, int val) {
  if(s == e) {
    tree[idx].sum = arr[pos] = val;
    tree[idx].prefix = max(0, val);
    return;
  }

  int m = mid(s, e);
  if(pos > m) {
    update(Right, m+1, e, pos, val);
  } else {
    update(Left, s, m, pos, val);
  }

  tree[idx].sum = tree[Left].sum + tree[Right].sum;
  tree[idx].prefix = max(tree[Left].prefix, tree[Left].sum + tree[Right].prefix);
}

ll query(int idx, int s, int e, int qs, int qe) {
  if(e < qs or s > qe) return 0;

  if(s >= qs && e <= qe) return tree[idx].prefix;

  int m = mid(s, e);
  ll left = query(Left, s, m, qs, qe);
  ll right = query(Right, m+1, e, qs, qe);
  
  return left+right;
}

void solve() {
  int n, q;
  inp(n, q);

  arr.resize(n+1);
  tree.resize(4*n);

  f(i, 1, n) inp(arr[i]);

  build(1, 1, n);

  while(q--) {
    int qt;
    inp(qt);

    if(qt == 1) {
      int k, u;
      inp(k, u);

      update(1, 1, n, k, u);
    } else {
      int a, b;
      inp(a, b);

      out(query(1, 1, n, a, b), '\n');
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
