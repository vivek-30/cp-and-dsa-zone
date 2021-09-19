#include <bits/stdc++.h>
using namespace std;

#define null NULL
#define endl "\n"
#define inf INT_MAX
#define minf INT_MIN
#define mod 998244353
#define ll long long int
#define all(v) v.begin(), v.end()
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

void solve(vi &arr, int n) {
  
  int largest = *max_element(all(arr));
  int cntLarge = count(all(arr), largest);
  int k = count(all(arr), largest-1);

  int total = 1, invalid = 1;
  f(i, 2, n) {
    total = (total * i) % mod;

    if(i != k+1)
      invalid = (invalid * i) % mod;
  }

  if(cntLarge == 1) {
    total = (total - invalid + mod) % mod;
  }

  cout<<total<<endl;
  
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

  ll t;
  cin >> t;
  f(i, 1, t) {
    int n;
    cin>>n;
    vi arr(n);
    f(j, 0, n-1) cin>>arr[j];
    solve(arr, n);
  }

  #ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
