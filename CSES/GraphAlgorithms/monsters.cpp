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

int n, m;

bool isValid(int i, int j, vs &arr) {
  if(i < 0 or j < 0 or i >= n or j >= m) return false;
  if(arr[i][j] == '#' or arr[i][j] == 'm') return false;

  return true;
}

bool isBoundary(int i, int j) {
  return (i == 0 or j == 0 or i == n-1 or j == m-1);
}

char getDir(int curr_i, int curr_j, int prev_i, int prev_j) {
  if(curr_i == prev_i && curr_j == prev_j+1) return 'R';
  if(curr_i == prev_i && curr_j == prev_j-1) return 'L';
  if(curr_i == prev_i+1 && curr_j == prev_j) return 'D';

  return 'U';
}

void bfs(int x, int y, vs &arr, vvi &dist) {
  vector<vb> visited(n, vb(m));

  queue<pii> q;
  q.push({x, y});

  dist[x][y] = 0;

  vii dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

  while(!q.empty()) {
    int i = q.front().fi;
    int j = q.front().se;

    q.pop();

    for(pii curr: dir) {
      if(isValid(i + curr.fi, j + curr.se, arr) && !visited[i + curr.fi][j + curr.se]) {
        visited[i + curr.fi][j + curr.se] = 1;
        q.push({i + curr.fi, j + curr.se});
        dist[i + curr.fi][j + curr.se] = min(dist[i + curr.fi][j + curr.se], dist[i][j] + 1);
      }
    }
  }
}

string res = "";

bool bfs2(int x, int y, vs &arr, vvi &dist) {
  vector<vb> visited(n, vb(m));

  queue<pii> q;
  q.push({x, y});

  dist[x][y] = 0;

  vvi store(n, vi(m));
  vector<vector<char> > mark(n, vector<char>(m));

  vii dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

  while(!q.empty()) {
    int i = q.front().fi;
    int j = q.front().se;

    q.pop();

    for(pii curr: dir) {
      if(isValid(i + curr.fi, j + curr.se, arr) && !visited[i + curr.fi][j + curr.se]) {
        visited[i + curr.fi][j + curr.se] = 1;
        q.push({i + curr.fi, j + curr.se});
        mark[i + curr.fi][j + curr.se] = getDir(i + curr.fi, j + curr.se, i, j);
        store[i + curr.fi][j + curr.se] = store[i][j] + 1;
        if(store[i + curr.fi][j + curr.se] < dist[i + curr.fi][j + curr.se] && isBoundary(i + curr.fi, j + curr.se)) {
          int a = i + curr.fi, b = j + curr.se;
          
          while(true) {
            res = mark[a][b] + res;
    
            if(mark[a][b] == 'L') b++;
            else if(mark[a][b] == 'R') b--;
            else if(mark[a][b] == 'U') a++;
            else a--;
    
            if(a == x and b == y) break;
          }
 
          return true;
        }
      }
    }

    return false;
  } 

  return false; 
}

void solve(int tc) {
  inp(n, m);

  vs arr(n);
  vvi dist(n, vi(m, inf));

  for(string &s: arr) inp(s);

  int x, y;
  f(i, 0, n-1) {
    f(j, 0, m-1) {
      if(arr[i][j] == 'M') bfs(i, j, arr, dist);
      if(arr[i][j] == 'A') x = i, y = j;
    }
  }

  if(bfs2(x, y, arr, dist)) {
    py
    out(res.sz, br, res, br);
  } else out("IMPOSSIBLE\n");
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
