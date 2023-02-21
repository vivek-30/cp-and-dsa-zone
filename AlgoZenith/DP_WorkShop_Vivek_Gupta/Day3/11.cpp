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

vi dp(200005, -1);

int predict(int x) {
  if(x <= 1) return dp[x] = x;

  if(dp[x] == -1) {
    int i = 0;
    bool flag = 1;
    while((1<<i) <= x && flag) {
      flag = predict(x-(1<<i));
      i++;
    }
    dp[x] = 1 - (int)flag;
  }

  return dp[x];
}

void solve(int tc) {
  int x;
  cin>>x;

  if(dp[x]) {
    cout<<"Vivek\n";
  } else cout<<"Abhishek\n";
}

void solve2(int tc) {
  int x;
  cin>>x;

  if(x%3 == 0) {
    cout<<"Abhishek\n";
  } else cout<<"Vivek\n";
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

  f(i, 0, 200004) predict(i);

  int tc = 1;
  cin >> tc;

  f(t, 1, tc) {
    solve2(t);
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
