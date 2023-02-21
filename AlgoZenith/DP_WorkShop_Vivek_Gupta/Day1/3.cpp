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

int locations[15], n;
vii dir = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}};

bool isValid(int row, int col) {

  // queen way attack
  f(i, 0, row-1) {
    int prev_row = i, prev_col = locations[i];
    if(col == prev_col or abs(prev_col - col) == abs(prev_row - row)) return false;
  }

  // knight way attack
  for(pii p: dir) {
    int new_row = row + p.fi;
    int new_col = col + p.se;
    if(new_row >= 0 and new_col >= 0 and new_col <= n-1) {
      int prev_col = locations[new_row];
      if(prev_col == new_col) return false;
    }
  }

  //concise way to check L shaped Moves
  // f(i, 0, row-1) {
  //   if((abs(i - row) == 2 && abs(locations[i] - col) == 1) or (abs(i - row) == 1 && abs(locations[i] - col) == 2)) return false;
  // }

  return true;
}

int queens(int row = 0) {
  if(row == n) {
    return 1;
  }

  int ans = 0;

  f(col, 0, n-1) {
    if(isValid(row, col)) {
      locations[row] = col;
      ans += queens(row+1);
      locations[row] = -1;
    }
  }

  return ans;
}

void solve(int tc) {
  cin>>n;

  memset(locations, -1, sizeof(locations));

  cout << queens() << endl;
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
  // cin >> tc;

  f(t, 1, tc) {
    solve(t);
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
