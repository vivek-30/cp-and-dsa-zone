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

bool feasible(ll val, ll max, ll pos, ll n) {
  if((max - val) >= ((n - pos)*val)) {
    return true;
  }

  return false;
}

ll possible(ll s, ll e, ll max, ll pos, ll n) {

  ll ans = s, m;

  while(s <= e) {
    
    m = mid(s, e);

    if(feasible(m, max, pos, n)) {
      ans = m;
      s = m +1 ;
    } else {
      e = m - 1;
    }
  }

  return ans;
}

ll solve(ll n, ll s) {
  if(n == 1)
    return s;

  int m = ceil((n>>1));
  m = (n&1) ? m+1 : m;


  return possible(0, s, s, m, n);
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  f(i, 1, t) {
    ll n, s;
    cin>>n>>s;

    cout<<solve(n, s)<<endl;
  }

  return 0;
}
