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
void out(T&&... args) { ((cout << args << " "), ...);}
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for(ll i = s; i <= e; i++)
#define fr(i, s, e) for(ll i = s; i >= e; i--)
#define logarr(arr, s, e) for(int i = s; i <= e; i++) cout<<arr[i]<<" "; cout<<endl;
#define bitc(n) __builtin_popcount(n)
#define mp make_pair
#define pb push_back
#define sz size()
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define fi first
#define se second
#define INF 2e18

#define Left (2 * idx)
#define Right (2 * idx + 1)

int n;
vi arr;
vll tree, lazy_tree;

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

void update(int idx, int s, int e, int qs, int qe, int val) {
  if(lazy_tree[idx] != 0) {
    tree[idx] += (e - s + 1) * lazy_tree[idx];
    if(s != e) {
      lazy_tree[Left] += lazy_tree[idx];
      lazy_tree[Right] += lazy_tree[idx];
    }
    lazy_tree[idx] = 0;
  }

  if(e < qs or s > qe) return;

  if(s >= qs && e <= qe) {
    tree[idx] += (e - s + 1) * val;
    if(s != e) {
      lazy_tree[Left] += lazy_tree[idx];
      lazy_tree[Right] += lazy_tree[idx];
    }
    return;
  }

  int m = mid(s, e);
  update(Left, s, m, qs, qe, val);
  update(Right, m+1, e, qs, qe, val);

  tree[idx] = tree[Left] + tree[Right];
}

ll query(int idx, int s, int e, int qs, int qe) {

  if(lazy_tree[idx] != 0) {

    tree[idx] += (e - s + 1) * lazy_tree[idx];

    if(s != e) {
      lazy_tree[Left] += lazy_tree[idx];
      lazy_tree[Right] += lazy_tree[idx];
    }

    lazy_tree[idx] = 0;
  }

  if(e < qs or s > qe) return 0;

  if(s >= qs && e <= qe) {
    return tree[idx];
  }

  int m = mid(s, e);
  return query(Left, s, m, qs, qe) + query(Right, m+1, e, qs, qe);
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  clock_t begin = clock();

  inp(n);

  arr.resize(n+1);
  tree.resize(4*n), lazy_tree.assign(4*n, 0);

  f(i, 1, n) inp(arr[i]);

  build(1, 1, n);

  int q;
  inp(q);

  f(i, 1, q) {
    int qt;
    inp(qt);

    if(qt == 1) {
      
      int l, r, val;
      inp(l, r, val);
      update(1, 1, n, l, r, val);

    } else {
      
      int x;
      inp(x);
      cout<<query(1, 1, n, x, x)<<endl;

    }
  }


  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
