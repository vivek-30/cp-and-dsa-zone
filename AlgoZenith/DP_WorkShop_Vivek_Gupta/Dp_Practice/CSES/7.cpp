#include <bits/stdc++.h>
using namespace std;

#define inf 2e18
#define minf -2e18
#define mod 1000000007
#define int long long int
#define ld long double
#define all(v) v.begin(), v.end()
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<char, int> mci;
template<typename... T>
void inp(T&... args) { ((cin >> args), ...);}
template<typename... T>
void out(T&&... args) { ((cout << args), ...);}
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

// Gives TLE
void solve2(int tc) {
  int n, x;
  inp(n, x);

  vi price(n+1), pages(n+1);
  f(i, 1, n) inp(price[i]);
  f(i, 1, n) inp(pages[i]);

  int sum = accumulate(all(pages), 0);

  vi prev_dp(sum+1, inf), curr_dp(sum+1, inf);

  prev_dp[0] = curr_dp[0] = 0;

  f(i, 1, n) {
    f(j, 1, sum) {
      curr_dp[j] = prev_dp[j];
      if(pages[i] <= j) {
        int cost = prev_dp[j - pages[i]];
        if(cost != inf) cost += price[i];
        curr_dp[j] = min(curr_dp[j], cost);
      }
    }

    f(k, 1, sum) {
      prev_dp[k] = curr_dp[k];
      curr_dp[k] = inf;
    }
  }

  fr(i, sum , 0) {
    if(prev_dp[i] <= x) {
      out(i, br);
      break;
    }
  }
}

// AC Solution
void solve(int tc) {
  int n, x;
  inp(n, x);

  vi price(n+1), pages(n+1);
  f(i, 1, n) inp(price[i]);
  f(i, 1, n) inp(pages[i]);

  vi prev_dp(x+1), curr_dp(x+1);
  
  f(i, 1, n) {
    f(j, 1, x) {
      curr_dp[j] = prev_dp[j];
      if(price[i] <= j) {
        curr_dp[j] = max(curr_dp[j], prev_dp[j-price[i]] + pages[i]);
      }
    }

    f(k, 1, x) {
      prev_dp[k] = curr_dp[k];
    }
  }

  out(prev_dp[x], br);
}

int32_t main() {

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
