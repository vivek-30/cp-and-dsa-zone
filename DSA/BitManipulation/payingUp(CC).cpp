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

ll getSum(int mask, vi& arr) {
  ll sum = 0, pos = 0;
  while(mask) {
    if((mask & 1) == 1) {
      sum += arr[pos];
    }
    pos++;
    mask = mask>>1;
  }

  return sum;
}

bool solve(ll n, ll m, vi &arr) {

  f(i, 0, ((1<<n)-1)) {
    if(getSum(i, arr) == m) {
      return true;
    }
  }

  return false;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  f(i, 1, t) {
    ll n, m;
    cin>>n>>m;

    vi arr(n);
    f(i, 0, n-1)
      cin>>arr[i];

    cout<<((solve(n, m, arr) == true) ? "Yes" : "No")<<endl;

  }

  return 0;
}
