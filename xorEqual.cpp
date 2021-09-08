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

void solve(ll &n, ll &x, vll &arr) {

  if(n == 1) {
    cout<<1<<" "<<0<<endl;
    return;
  }

  ll xr;

  map<ll, pll> m;

  f(i, 0, n-1) {
    
    xr = (arr[i] ^ x);
    
    if(m.count(arr[i])) {
      m[arr[i]].fi++;
    }
    else {
      m[arr[i]] = mp(1, 0);
    }
    
    if(m.count(xr)) {
      m[xr].fi++;
      m[xr].se++;
    } else {
      m[xr] = mp(1, 1);
    }
  }

  ll minAns = inf, maxAns = minf;
  for(auto it = m.begin(); it != m.end(); it++) {
    if(it == m.begin()) {
      maxAns = max(maxAns, (*it).se.fi);
      minAns = min(minAns, (*it).se.se);
    } else {
      if((maxAns - minAns) <  (((*it).se.fi) - ((*it).se.se))) {
        maxAns = (*it).se.fi;
        minAns = (*it).se.se;
      }
    }
  }

  cout<<maxAns<<" "<<minAns<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  f(i, 1, t) {
    ll n, x;
    cin>>n>>x;

    vll arr(n);
    f(j, 0, n-1) {
      cin>>arr[j];
    }

    solve(n, x, arr);
  }

  return 0;
}
