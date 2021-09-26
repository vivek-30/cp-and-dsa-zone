#include <bits/stdc++.h>
using namespace std;

#define null NULL
#define endl "\n"
#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
#define all(v) v.begin(), v.end()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii > vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vi > vvi;
typedef vector<vll > vvll;
typedef map<int, int> mii;
typedef map<char, int> mci;
template<typename... T>
void inp(T&... args) { ((cin >> args), ...);}
template<typename... T>
void out(T&&... args) { ((cout << args << " "), ...);}
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

int findPos(int i, vi &arr, int n) {
  
  int s = i, e = n-1, m;
  bool flag = false;

  int pos = -1;

  while(s <= e) {
    
    m = mid(s, e);
    flag = false;

    if(arr[m] <= arr[i]) {
      fr(j, m-1, i+1) {
        if(arr[j] > arr[m]) {
          flag = true;
          break;
        }
      }

      if(i - m == 1) {
        return i+1;
      }

      if(flag) {
        e = m - 1;
      } else {
        pos = m;
        s = m+1;
      }
    } else {
      e = m-1;
    }
  }

  return pos;
}

int solve(int i, int n, vi &arr, vi &dp) {
  
  if(i == n-1)
    return 0;
  
  if(i >= n)
    return inf;

  if(dp[i] != inf)
    return dp[i];

  int pos = findPos(i, arr, n);
  
  if(pos == -1){
    return inf;
  }

  int ans = solve(pos, n, arr, dp);
  return dp[i] = ans != inf ? 1 + ans : ans;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  clock_t begin = clock();

  int t;
  cin>>t;

  while(t--) {
    
    int n;
    inp(n);

    vi arr(n);
    f(i, 0, n-1){
      inp(arr[i]);
    }

    vi dp(n, inf);
    int ans = solve(0, n, arr, dp);
    if(ans == inf) {
      ans = -1;
    }
    cout<<ans<<endl;
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
