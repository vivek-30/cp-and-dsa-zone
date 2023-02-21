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

double dp[305][305][305];

double solve(int x, int y, int z, int n) {
  
  if(x < 0 or y < 0 or z < 0)
    return 0;
  
  if(x == 0 and y == 0 and z == 0)
    return 0;

  if(dp[x][y][z] > - 0.9)
    return dp[x][y][z];

  double exp = (n + x * solve(x-1, y, z, n) + y * solve(x+1, y-1, z, n) + z * solve(x, y+1, z-1, n));
  return dp[x][y][z] = exp / (x + y + z);
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, inp;
  cin>>n;

  int x = 0, y = 0, z = 0;
  f(i, 1, n) {
    cin>>inp;
    if(inp == 1)
      x++;
    else if(inp == 2)
      y++;
    else z++;
  }

  memset(dp, -1, sizeof(dp));

  cout<<fixed<<setprecision(10)<<solve(x, y, z, n)<<endl;

  return 0;
}
