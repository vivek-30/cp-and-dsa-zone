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
#define INF 2e18
 
int n, m, mx;
string res;
 
void getPath(int i, int j, int cnt, string curr, vs &arr) {
  if(i < 0 or j < 0 or i >= n or j >= m) return;
  
  if(arr[i][j] == '$' or arr[i][j] == '#') return;
 
  if(arr[i][j] == 'B') {
    if(cnt < mx) {
      mx = cnt;
      res = curr;
    }
    return;
  }
 
  if(cnt >= mx) return;
 
  char ch = arr[i][j];
  arr[i][j] = '$';
 
  getPath(i-1, j, cnt+1, curr + "U", arr);
  getPath(i+1, j, cnt+1, curr + "D", arr);
  getPath(i, j-1, cnt+1, curr + "L", arr);
  getPath(i, j+1, cnt+1, curr + "R", arr);
 
  arr[i][j] = ch;
  return;
}
 
void solve(int tc) {
  inp(n, m);
 
  vs arr(n);
  for(string &s: arr) inp(s);
 
  res = "";
  mx = inf;
 
  f(i, 0, n-1) {
    f(j, 0, m-1) {
      if(arr[i][j] == 'A') {
        getPath(i, j, 0, "", arr);
        if(res != "") {
          py
          out(res.sz, br, res, br);
        }
        else pn
        return;
      }
    }
  }
}
 
bool check(int x, int y, vs &arr) {
  if(x < 0 or y < 0 or x >= n or y >= m) return false;
 
  if(arr[x][y] == '#') return false;
 
  return true;
}
 
bool bfs(int x, int y, vs &arr) {
  queue<pii> q;
  q.push({x, y});
 
  vector<vb> visited(n, vb(m));
  vector<vector<char> > dir(n, vector<char> (m));
  visited[x][y] = 1;
 
  bool flag = true;
 
  while(!q.empty()) {
    pii curr = q.front();
    q.pop();
 
    if(arr[curr.fi][curr.se] == 'B') {
      
      int a = curr.fi, b = curr.se;
      while(true) {
        res = dir[a][b] + res;
 
        if(dir[a][b] == 'L') b++;
        else if(dir[a][b] == 'R') b--;
        else if(dir[a][b] == 'U') a++;
        else a--;
 
        if(a == x and b == y) break;
      }
 
      return true;
    }
 
    if(check(curr.fi, curr.se-1, arr) and not visited[curr.fi][curr.se-1]) {
      visited[curr.fi][curr.se-1] = 1;
      dir[curr.fi][curr.se-1] = 'L';
      q.push({curr.fi, curr.se-1});
    }
 
    if(check(curr.fi, curr.se+1, arr) and not visited[curr.fi][curr.se+1]) {
      visited[curr.fi][curr.se+1] = 1;
      dir[curr.fi][curr.se+1] = 'R';
      q.push({curr.fi, curr.se+1});
    }
 
    if(check(curr.fi-1, curr.se, arr) and not visited[curr.fi-1][curr.se]) {
      visited[curr.fi-1][curr.se] = 1;
      dir[curr.fi-1][curr.se] = 'U';
      q.push({curr.fi-1, curr.se});
    }
 
    if(check(curr.fi+1, curr.se, arr) and not visited[curr.fi+1][curr.se]) {
      visited[curr.fi+1][curr.se] = 1;
      dir[curr.fi+1][curr.se] = 'D';
      q.push({curr.fi+1, curr.se});
    }
  }
 
  return false;
}
 
void solve2(int tc) {
  inp(n, m);
 
  vs arr(n);
  for(string &s: arr) inp(s);
 
  int x = -1, y = -1;
 
  f(i, 0, n-1) {
    f(j, 0, m-1) {
      if(arr[i][j] == 'A') {
        x = i;
        y = j;
        break;
      }
    }
 
    if(x != -1) break;
  }
 
  if(bfs(x, y, arr)) {
    py
    out(res.sz, br, res, br);
  } else pn
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
    solve2(t);
  }
 
  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif
 
  return 0;
}