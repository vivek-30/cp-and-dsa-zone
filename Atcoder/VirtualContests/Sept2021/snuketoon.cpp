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

map<int, pair<bool, int> > shots;

ll solve(ll pos, ll time, ll maxTime) {

  if(time > maxTime)
    return 0;
  
  ll curr = 0;

  if(shots.count(time)) {
    if(shots[time].fi == false && pos < shots[time].se) {
      curr = shots[time].se - pos;
    } else if(shots[time].fi == true && pos > shots[time].se) {
      curr = pos - shots[time].se;
    }
  }

  ll damage =  curr + min({solve(pos+1, time + 1, maxTime) , solve(pos-1, time + 1, maxTime), solve(pos, time + 1, maxTime) });
  return damage;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin >> n;
  int d;

  ll maxTime = -1;

  f(i, 1, n) {
    ll t, x;
    cin>>t;
    cin>>d;
    cin>>x;
    maxTime = max(maxTime, t);

    shots[t] = mp((d == 1 ? true : false), x);
  }

  cout<<solve(0, 0, maxTime)<<endl;

  return 0;
}
