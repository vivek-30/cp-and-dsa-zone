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

ll power_recursive(ll x, ll n) {
  
  if(n == 0) {
    return 1;
  }

  ll ans = power_recursive(x, n>>1);
  if(n&1) {
    return (ans % mod * ans % mod * x % mod) % mod;
  } else {
    return (ans % mod * ans % mod) % mod;
  }
}

ll power_iterative(ll x, ll n) {
  ll ans = 1;
  while(n) {
    if(n&1) {
      ans = (ans % mod * x % mod) % mod;
    } 
    n >>= 1;
    x = (x % mod * x % mod) % mod;
  }

  return ans;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  f(i, 1, t) {
    ll x, n;
    cin>>x>>n;

    cout<<power_recursive(x, n)<<" "<<power_iterative(x, n)<<endl;
  }

  return 0;
}
