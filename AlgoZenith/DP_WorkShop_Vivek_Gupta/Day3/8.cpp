#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
#define ld long double
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
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for(int i = s; i <= e; i++)
#define fr(i, s, e) for(int i = s; i >= e; i--)
#define logarr(s, e, arr) for(int i = s; i <= e; i++) cout << arr[i] << " ";  cout << "\n";
#define bitc(n) __builtin_popcountll(n)
#define debug(x) cout << #x << " = " << x << "\n";
#define mp make_pair
#define eb emplace_back
#define sz size()
#define br "\n"
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define py cout << "YES" << "\n";
#define pn cout << "NO" << "\n";
#define fi first
#define se second
#define INF 2e18

ll arr[505], prefix[505], dp[505][505];

ll getAns(int i, int j) {
  if(i == j) return 0;

  if(dp[i][j] != -1) return dp[i][j];

  ll ans = INF, x, y, val1, val2;
  f(k, i, j-1) {
    x = getAns(i, k);
    y = getAns(k+1, j);
    val1 = (prefix[k] - prefix[i-1])%100;
    val2 = (prefix[j] - prefix[k])%100;
    ans = min(ans, x + y + (val1 * val2));
  }

  return dp[i][j] = ans;
}

void solve(int tc) {
  int n;
  cin>>n;

  memset(dp, -1, sizeof dp);

  f(i, 1, n) {
    cin>>arr[i];
    prefix[i] = arr[i] + prefix[i-1];
  }

  cout<<getAns(1, n)<<endl;
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

  int tc = 1;

  f(t, 1, tc) {
    solve(t);
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
