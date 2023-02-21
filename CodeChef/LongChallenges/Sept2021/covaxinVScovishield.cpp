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

ll ans = 0;
ll a, b, c, d;
ll p, q, r, s, t, m;

void update() {
  a = ((a + ans*t) % m) + p;
  b = ((b + ans*t) % m) + q;
  c = ((c + ans*t) % m) + r;
  d = ((d + ans*t) % m) + s;

  ans = 0;
}

void updateCost(ll &medicine, ll &x, ll &y, ll &doseNumber) {
  medicine = (x + ((doseNumber - 1) * y));
}

void solve(ll x) {
  
  ll covaxin, covishield, covaxinDose, covishieldDose;
  covishieldDose = covaxinDose = 1;

  updateCost(covaxin, a, b, covaxinDose);
  updateCost(covishield, c, d, covishieldDose);
    
  while(x >= 0 and x >= covaxin and x >= covishield) {
    if(covaxin <= covishield) {
      x -= covaxin;
      covaxinDose++;
      updateCost(covaxin, a, b, covaxinDose);
    } else {
      x -= covishield;
      covishieldDose++;
      updateCost(covishield, c, d, covishieldDose);
    }
    ans++;
  }
  
  while(x >= covaxin) {
    x -= covaxin;
    covaxinDose++;
    updateCost(covaxin, a, b, covaxinDose);
    ans++;
  }

  while(x >= covishield) {
    x -= covishield;
    covishieldDose++;
    updateCost(covishield, c, d, covishieldDose);
    ans++;
  }

  cout<<ans<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll I, x;
  cin >> I;
  
  cin>>x>>a>>b>>c>>d;
  cin>>p>>q>>r>>s>>t>>m;
  
  f(i, 1, I) {

    if(i > 1) {
      update();
    }

    solve(x);  
  }

  return 0;
}
