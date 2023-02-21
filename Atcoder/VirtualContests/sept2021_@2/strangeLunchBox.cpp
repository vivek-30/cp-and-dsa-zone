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

int dp[305][305][305];

int solve2(int n, int x, int y, vii &arr) {

  f(i, 0, 304) {
    f(j, 0, 304) {
      f(k, 0, 304) {
        dp[i][j][k] = inf;
      }
    }
  }

  f(i, 0, 304) {
    dp[i][0][0] = 0;
  } 

  int a, b, curr;
  
  f(i, 1, n) {
    f(j, 1, x) {
      f(k, 1, y) {
        
        dp[i][j][k] = dp[i-1][j][k];
        
        a = j - arr[i-1].fi;
        b = k - arr[i-1].se;

        if(a >= 0 && b >= 0) {
          curr = dp[i-1][a][b];
          if(curr != inf) {
            curr += 1;
          }
        } else {
          curr = 1;
        }

        dp[i][j][k] = min(dp[i][j][k], curr);
      }
    }
  }

  return dp[n][x][y];
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin>>n;

  int x, y, totalX = 0, totalY = 0;
  cin>>x>>y;

  vii arr(n);
  f(i, 0, n-1) {
    cin>>arr[i].fi>>arr[i].se;
    totalX += arr[i].fi;
    totalY += arr[i].se;
  }

  if(totalX < x or totalY < y) {
    cout<<-1<<endl;
  } else {
    cout<<solve2(n, x, y, arr)<<endl;
  }

  return 0;
}
