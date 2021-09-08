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

ll solve(int n, vector<pll> &coords, ll x) {

  if(n < 0)
    return 0;

  if(n == 0) {
    if(coords[n].fi == x and coords[n].se == x) {
      return 0;
    } else if(coords[n].fi == x or coords[n].se == x) {
      return 1;
    } else return 2;
  } 

  min(solve(x)

}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  f(i, 1, t) {
    int n;
    cin>>n;

    vector<pll> coords(n);
    f(i, 0, n-1) {
      cin>>coords[i].fi;
    }

    f(i, 0, n-1) {
      cin>>coords[i].se;
    }
    vi freq(n, 0);
    int maxNo = minf, maxIdx;

    f(i, 0, n-1) {
      if(coords[i].fi == coords[i].se) {
        freq[i] = freq[i] + 1;
      }
      if(maxNo < freq[i]) {
        maxIdx = i;
        maxNo = freq[i];
      }
    }

    cout<<solve(n-1, coords, coords[maxIdx].fi)<<endl;
  }

  return 0;
}
