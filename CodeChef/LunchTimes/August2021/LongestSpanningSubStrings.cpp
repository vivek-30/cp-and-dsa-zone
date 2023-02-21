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
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define fi first
#define se second
#define INF 2e18

class DSU {
  vi ds;

  public:

  DSU() {
    ds.assign(105, -1);
  }

  int search(int x) {
    if(ds[x] < 0) {
      return x;
    }

    return ds[x] = search(ds[x]);
  }

  bool combine(int a, int b) {
    int pa = search(a);
    int pb = search(b);

    if(pa == pb) 
      return false;

    if(ds[pa] < ds[pb]) {
      ds[pa] += ds[pb];
      ds[pb] = pa;
    } else {
      ds[pb] += ds[pa];
      ds[pa] = pb;
    }

    return true;
  }

};

DSU obj;

int findLength(string s, string t) {
  
  int n = s.length(), m = t.length();

  vvi dp(n+1, vi(m+1, 0));
  int len = 0;

  f(i, 1, n) {
    f(j, 1, m) {
      if(s[i-1] == t[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
        len = max(len, dp[i][j]);
      } else {
        dp[i][j] = 0;
      }
    }
  }

  return len;
}

bool cmp(tuple<int, int, int> &a, tuple<int, int, int> &b) {
  return (get<0>(a) <= get<0>(b));
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
    
    int n;
    inp(n);

    vector<string> v(n);

    f(i, 0, n-1) {
      cin>>v[i];
    }

    vector<tuple<int, int, int> > res;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(i != j) {
          int len = findLength(v[i], v[j]);
          res.pb(make_tuple(len, i, j));
        }
      }
    }

    ll ans = 0;
    sort(all(res), cmp);
    f(i, 0, res.size()-1) {
      if(obj.combine(get<1>(res[i]), get<2>(res[i]))) {
        ans += get<0>(res[i]);
      }
    }

    cout<<ans<<endl;
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
