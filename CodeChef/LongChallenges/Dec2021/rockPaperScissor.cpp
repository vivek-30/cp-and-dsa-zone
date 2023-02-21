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

vector<char> tree, str;
int n;

void build(int idx, int s, int e) {

  if(s == e) {
    tree[idx] = str[s];
    return;
  }

  int m = mid(s, e);
  build(Left, s, m);
  build(Right, m+1, e);

  if(tree[Left] == 'R' or tree[Right] == 'R') {
    if(tree[Left] == 'P' or tree[Right] == 'P') tree[idx] = 'P';
    else tree[idx] = 'R';
  } else if(tree[Left] == 'P' or tree[Right] == 'P') {
    if(tree[Left] == 'S' or tree[Right] == 'S') tree[idx] = 'S';
    else tree[idx] = 'P';
  }
  else {
    if(tree[Left] == 'R' or tree[Right] == 'R') tree[idx] = 'R';
    else tree[idx] = 'S';
  }
}

void update(int idx, int s, int e, int pos) {
  if(s == e) {
    tree[idx] = '#';
    return;
  }

  int m = mid(s, e);
  if(pos > m) {
    update(Right, m+1, e, pos);
  } else {
    update(Left, s, m, pos);
  }

  if(tree[Left] == '#' && tree[Right] == '#') tree[idx] = '#';
  else if(tree[Left] == '#') tree[idx] = tree[Right];
  else if(tree[Right] == '#') tree[idx] = tree[Left];
  else if(tree[Left] == 'R' or tree[Right] == 'R') {
    if(tree[Left] == 'P' or tree[Right] == 'P') tree[idx] = 'P';
    else tree[idx] = 'R';
  } else if(tree[Left] == 'P' or tree[Right] == 'P') {
    if(tree[Left] == 'S' or tree[Right] == 'S') tree[idx] = 'S';
    else tree[idx] = 'P';
  }
  else {
    if(tree[Left] == 'R' or tree[Right] == 'R') tree[idx] = 'R';
    else tree[idx] = 'S';
  }
}

char query(int idx, int s, int e, int qs, int qe) {
  if(e < qs or s > qe) return '#';

  if(s >= qs && e <= qe) return tree[idx];

  int m = mid(s, e);
  char left = query(Left, s, m, qs, qe);
  char right = query(Right, m+1, e, qs, qe);

  if(left == '#' && right == '#') return '#';
  else if(left == '#') return right;
  else if(right == '#') return left;
  else if(left == 'R' or right == 'R') {
    if(left == 'P' or right == 'P') return 'P';
    else return 'R';
  } else if(left == 'P' or right == 'P') {
    if(left == 'S' or right == 'S') return 'S';
    else return 'P';
  }
  else {
    if(left == 'R' or right == 'R') return 'R';
    else return 'S';
  }
}

void solve() {
  string s;
  inp(n, s);

  str.resize(n+1);
  tree.resize(4*n);

  f(i, 1, n) {
    str[i] = s[i-1];
  }

  build(1, 1, n);

  string ans = "";
  f(i, 1, n) {
    ans += query(1, 1, n, i, n);
    update(1, 1, n, i);
  }

  out(ans, '\n');
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
  cin>>t;

  while(t--) {
    solve();
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
