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

double solve(int n, int x, vector<double> &arr, vector<vector<double> > &dp) {

  if(x == 0)
    return 1;
  
  if(n == 0)
    return 0;

  if(dp[n][x] > -0.9)
    return dp[n][x];

  return dp[n][x] = solve(n-1, x, arr, dp) * (1 - arr[n-1]) + solve(n-1, x-1, arr, dp) * arr[n-1];
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<double> arr(n);

  f(i, 0, n-1) {
    cin>>arr[i];
  }
  int x = (n/2)+1;
  vector<vector<double> > dp(n+1, vector<double> (x+1, -1));

  cout<<fixed<<setprecision(10)<<solve(n, x, arr, dp)<<endl;

  return 0;
}
