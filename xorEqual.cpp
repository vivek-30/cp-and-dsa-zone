#include <bits/stdc++.h>
using namespace std;

#define null NULL
#define endl "\n"
#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,string> pis;
typedef pair<string,int> psi;
typedef pair<string,string> pss;
typedef vector<pii > vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vi > vvi;
typedef vector<vll > vvll;
typedef map<int, int> mii;
typedef map<string, string> mss;
typedef map<int, string> mis;
typedef map<string, int> msi;
#define mid(l, r) (l + (r - l) / 2)
#define f(i,s,n) for(ll i = s; i <= n; i++)
#define fr(i,s,e) for(ll i = s; i >= e; i--)
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define fi first
#define se second
#define INF 2e18

void solve(int &n, int &x, vi &arr) {

  map<int, int> m;
  int maxAns = minf, minAns = 0;

  f(i, 0, n-1) {
    m[arr[i]]++;
    maxAns = max(maxAns, m[arr[i]]);
  }

  for(auto it: m) {
    int key = it.fi, val = it.se;
    int curr = val;
    if(x != 0)
      curr += m[key^x];
    int req = val;

    if(curr > maxAns) {
      maxAns = curr;
      minAns = req;
    }
    else if(curr == maxAns) {
      minAns = min(minAns, req);
    }

  }

  cout<<maxAns<<" "<<minAns<<endl;
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

  ll t;
  cin >> t;
  f(i, 1, t) {
    int n, x;
    cin>>n>>x;

    vi arr(n);
    f(j, 0, n-1) {
      cin>>arr[j];
    }

    solve(n, x, arr);
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
