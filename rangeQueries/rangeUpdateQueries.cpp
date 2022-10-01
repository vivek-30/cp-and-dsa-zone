#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
#define ld long double
#define all(v) v.begin(), v.end()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef map<char, int> mci;
template <typename... T>
void inp(T &...args) { ((cin >> args), ...); }
template <typename... T>
void out(T &&...args) { ((cout << args), ...); }
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for (ll i = s; i <= e; i++)
#define fr(i, s, e) for (ll i = s; i >= e; i--)
#define logarr(s, e, arr) for (int i = s; i <= e; i++) cout << arr[i] << " ";cout << "\n";
#define bitc(n) __builtin_popcountll(n)
#define debug(x) cout << #x << " = " << x << "\n";
#define mp make_pair
#define eb emplace_back
#define sz size()
#define br "\n"
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int>>
#define py cout << "YES" << "\n";
#define pn cout << "NO" << "\n";
#define fi first
#define se second
#define INF 2e18

#define N 200005
#define Left (2 * idx)
#define Right (2 * idx + 1)

int n, q;
vll arr(N), tree(4 * N), lazy(4 * N);

void build(int idx, int s, int e)
{
  if (s > e)
    return;

  if (s == e)
  {
    tree[idx] = arr[s];
    return;
  }

  int m = mid(s, e);
  build(Left, s, m);
  build(Right, m + 1, e);

  tree[idx] = tree[Left] + tree[Right];
}

void update(int idx, int s, int e, int qs, int qe, int val)
{

  if (lazy[idx] != 0)
  { 
    tree[idx] += lazy[idx];

    if (s != e)
    {
      lazy[Left] += lazy[idx];
      lazy[Right] += lazy[idx];
    }

    lazy[idx] = 0;
  }

  if (s > e or s > qe or e < qs)
    return;

  if (s >= qs and e <= qe)
  {
    tree[idx] += val;

    if (s != e)
    {
      lazy[Left] += val;
      lazy[Right] += val;
    }

    return;
  }
  
  int m = mid(s, e);
  update(Left, s, m, qs, qe, val);
  update(1 + Left, m + 1, e, qs, qe, val);

  tree[idx] = tree[Left] + tree[Right];
}

ll query(int idx, int s, int e, int qs, int qe)
{

  if (s > e or s > qe or e < qs)
    return 0;

  if (lazy[idx] != 0)
  {
    tree[idx] += lazy[idx]; 

    if (s != e)
    {
      lazy[Left] += lazy[idx];
      lazy[Right] += lazy[idx];
    }

    lazy[idx] = 0;
  }

  if(s >= qs and e <= qe) {
    return tree[idx];
  }

  int m = mid(s, e);
  ll q1 = query(Left, s, m, qs, qe);
  ll q2 = query(1 + Left, m + 1, e, qs, qe);

  return q1 + q2;
}

void solve()
{
  inp(n, q);
  f(i, 0, n-1) inp(arr[i]);

  build(1, 0, n - 1);

  while(q--) {
    int qt;
    inp(qt);

    if(qt == 1) {
      int a, b, u;
      inp(a, b, u);

      update(1, 0, n-1, a-1, b-1, u);
    } else {
      int k;
      inp(k);

      out(query(1, 0, n-1, k-1, k-1), br);
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