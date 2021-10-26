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
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define fi first
#define se second
#define INF 2e18

#define MAX 200005

vi g[MAX];
vi level(MAX, 0);
int jump[MAX][21];

void solve(int src, int parent, int l) {
  
  jump[src][0] = parent;
  level[src] = l;

  for(int child: g[src]) {
    if(child != parent) {
      solve(child, src, l+1);
    }
  }
}

void preProcessLCA() {
  
  solve(1, 0, 0);
  int parent;

  f(i, 1, MAX-1) {
    f(j, 1, 20) {
      parent = jump[i][j-1];
      jump[i][j] = jump[parent][j-1];
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

  int n, q;
  inp(n, q);

  f(i, 2, n) {
    int e;
    inp(e);
   
    g[e].pb(i);
    g[i].pb(e);
  }

  preProcessLCA();

  f(i, 1, q) {
    int x, k;
    inp(x, k);

    int boss = x;

    f(j, 0, 20) {
      if(k & (1<<j)) {
        boss = jump[boss][j];
      }
    }

    if(boss == 0) {
      boss = -1;
    }

    cout<<boss<<endl;
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
