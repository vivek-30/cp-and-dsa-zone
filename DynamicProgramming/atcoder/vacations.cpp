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

class Activity {
  public:
    ll sw, cb, hw;   // sw - swim, cb - catch bug, hw - home work
    
    Activity() {
      sw = cb = hw = 0;
    }
};

void solve(int n, Activity arr[]) {
  
  vvll dp(n, vll(3, 0));
  dp[0][0] = arr[0].sw;
  dp[0][1] = arr[0].cb;
  dp[0][2] = arr[0].hw;

  f(i, 1, n-1) {
    dp[i][0] = arr[i].sw + max(dp[i-1][1], dp[i-1][2]);
    dp[i][1] = arr[i].cb + max(dp[i-1][0], dp[i-1][2]);
    dp[i][2] = arr[i].hw + max(dp[i-1][0], dp[i-1][1]);
  }

  cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin>>n;

  Activity arr[n];
  f(i, 0, n-1) {
    cin>>arr[i].sw>>arr[i].cb>>arr[i].hw;
  }

  solve(n, arr);

  return 0;
}
