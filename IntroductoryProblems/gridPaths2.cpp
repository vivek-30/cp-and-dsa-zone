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
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define fi first
#define se second
#define INF 2e18

#define N 3

int ans = 0;
string dir;
vector<vb > track(N, vb(N, false));

bool isPossible(int r, int c) {
  if(r < 0 or c < 0 or r >= N or c >= N or track[r][c]) {
    return false;
  }

  return true;
}

void solve(int r, int c, int pos) {
  
  if(r == (N-1) && c == 0) {
    ans++;
    return;
  }

  if(dir[pos] == '?') {

    if(isPossible(r+1, c)) {
      track[r+1][c] = true;
      solve(r+1, c, pos+1);
      track[r+1][c] = false;
    }

    if(isPossible(r, c+1)) {
      track[r][c+1] = true;
      solve(r, c+1, pos+1);
      track[r][c+1] = false;
    }

    if(isPossible(r-1, c)) {
      track[r-1][c] = true;
      solve(r-1, c, pos+1);
      track[r-1][c] = false;
    }

    if(isPossible(r, c-1)) {
      track[r][c-1] = true;
      solve(r, c-1, pos+1);
      track[r][c-1] = false;
    }
  
  } else {
    
    int x = r, y = c;
    if(dir[pos] == 'D') {
      x++;
    } else if(dir[pos] == 'U') {
      x--;
    } else if(dir[pos] == 'R') {
      y++;
    } else {
      y--;
    }

    if(isPossible(x, y)) {
      track[x][y] = true;
      solve(x, y, pos+1);
      track[x][y] = false;
    }
  }
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

  inp(dir);

  track[0][0] = true;
  solve(0, 0, 0);

  cout<<ans<<endl;

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
