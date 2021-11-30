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

vll arr, tree, lazy;

void build(int idx, int s, int e) {

  if(s == e) {
    tree[idx] = arr[s];
    return;
  }

  int m = mid(s, e);
  build(Left, s, m);
  build(Right, m+1, e);

  tree[idx] = tree[Left] + tree[Right];
}

void rangeUpdate(int idx, int s, int e, int qs, int qe, int val) {
  if(lazy[idx] != 0) {
    tree[idx] += (e - s + 1) * lazy[idx]; 
    if(s != e) {
      lazy[Left] += lazy[idx];
      lazy[Right] += lazy[idx];
    }
    lazy[idx] = 0;
  }

  if(e < qs or s > qe) return;

  if(s >= qs and e <= qe) {
    tree[idx] += (e - s + 1)*val;
    if(s != e) {
      lazy[Left] += val;
      lazy[Right] += val;
    }
    return;
  }

  int m = mid(s, e);
  rangeUpdate(Left, s, m, qs, qe, val);
  rangeUpdate(Right, m+1, e, qs, qe, val);

  tree[idx] = tree[Left] + tree[Right];
}

int rangeQuery(int idx, int s, int e, int qs, int qe) {
  if(e < qs or s > qe) return 0;

  if(lazy[idx] != 0) {
    tree[idx] += (e - s + 1)*lazy[idx];
    if(s != e) {
      lazy[Left] += lazy[idx];
      lazy[Right] += lazy[idx];
    }
    lazy[idx] = 0;
  }

  if(s >= qs and e <= qe) return tree[idx];

  int m = mid(s, e);
  return rangeQuery(Left, s, m, qs, qe) + rangeQuery(Right, m+1, e, qs, qe);
}

void solve() {
  int n, q;
  inp(n, q);

  arr.resize(n+1), tree.resize(4*n);
  lazy.assign(4*n, 0);

  f(i, 1, n) {
    inp(arr[i]);
  }

  while(q--) {
    int qt;
    inp(qt);

    if(qt == 1) {
      
      int a, b, u;
      inp(a, b, u);
      rangeUpdate(1, 1, n, a, b, u);

    } else {
      
      int k;
      inp(k);
      out(rangeQuery(1, 1, n, k, k), '\n');

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
