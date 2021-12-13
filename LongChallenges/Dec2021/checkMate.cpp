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
void out(T&&... args) { ((cout << args), ...);}
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for(ll i = s; i <= e; i++)
#define fr(i, s, e) for(ll i = s; i >= e; i--)
#define logarr(s, e, arr) for(int i = s; i <= e; i++) cout<<arr[i]<<" "; cout<<endl;
#define bitc(n) __builtin_popcount(n)
#define mp make_pair
#define pb push_back
#define sz size()
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define fi first
#define se second
#define INF 2e18

int xk, yk;

int getMoves() {
  int cnt = 0;
  
  if(xk - 1 >= 1) cnt++;
  if(xk + 1 <= 8) cnt++;

  if(yk - 1 >= 1) cnt++;
  if(yk + 1 <= 8) cnt++;

  if(xk - 1 >= 1 and yk - 1 >= 1) cnt++;
  if(xk - 1 >= 1 and yk + 1 <= 8) cnt++;

  if(xk + 1 <= 8 and yk - 1 >= 1) cnt++;
  if(xk + 1 <= 8 and yk + 1 <= 8) cnt++;

  return cnt;
}

bool topSafe(int x1, int y1, int x2, int y2) {
  if((x1 == xk && x2 == xk+1) || (x2 == xk && x1 == xk+1) || (x1 == xk && abs(yk - y1) > 1 && abs(yk - y2) > 1) || (x2 == xk && abs(yk - y2) > 1 && abs(yk - y1) > 1) || ((x1 == xk+1 || x2 == xk+1) && abs(yk - y1) > 1 && abs(yk - y2) > 1 && y1 != y2)) return true;
  
  return false;
}

bool leftSafe(int x1, int y1, int x2, int y2) {
  if((y1 == yk && y2 == yk+1) || (y2 == yk && y1 == yk+1) || (y1 == yk && abs(xk - x1) > 1 && abs(xk - x2) > 1) || (y2 == yk && abs(xk - x2) > 1 && abs(xk - x1) > 1) || ((y1 == yk+1 || y2 == yk+1) && abs(xk - x1) > 1 && abs(xk - x2) > 1 && x1 != x2)) return true;
  
  return false;
}

bool bottomSafe(int x1, int y1, int x2, int y2) {
  if((x1 == xk && x2 == xk-1) || (x2 == xk && x1 == xk-1) || (x1 == xk && abs(yk - y1) > 1 && abs(yk - y2) > 1) || (x2 == xk && abs(yk - y2) > 1 && abs(yk - y1) > 1) || ((x1 == xk-1 || x2 == xk-1) && abs(yk - y1) > 1 && abs(yk - y2) > 1 && y1 != y2)) return true;
  
  return false;
}

bool rightSafe(int x1, int y1, int x2, int y2) {
  if((y1 == yk && y2 == yk-1) || (y2 == yk && y1 == yk-1) || (y1 == yk && abs(xk - x1) > 1 && abs(xk - x2) > 1) || (y2 == yk && abs(xk - x2) > 1 && abs(xk - x1) > 1) || ((y1 == yk-1 || y2 == yk-1) && abs(xk - x1) > 1 && abs(xk - x2) > 1 && x1 != x2)) return true;
  
  return false;
}

bool canReachCorner(int x1, int y1, int x2, int y2) {
  if(xk == 1 && yk == 1) {
    
    if(topSafe(x1, y1, x2, y2)) return true;
    else if(leftSafe(x1, y1, x2, y2)) return true;
    else return false;

  } else if(xk == 1 && yk == 8) {

    if(topSafe(x1, y1, x2, y2)) return true;
    else if(rightSafe(x1, y1, x2, y2)) return true;
    else return false;

  } else if(xk == 8 && yk == 1) {

    if(leftSafe(x1, y1, x2, y2)) return true;
    else if(bottomSafe(x1, y1, x2, y2)) return true;
    else return false;

  } else {

    if(bottomSafe(x1, y1, x2, y2)) return true;
    else if(rightSafe(x1, y1, x2, y2)) return true;
    else return false;

  }

  return true;
}

bool canReachBoundary(int x1, int y1, int x2, int y2) {
  if(xk == 1) {
    
    if(topSafe(x1, y1, x2, y2)) return true;
    else return false;

  } else if(xk == 8) {
    
    if(bottomSafe(x1, y1, x2, y2)) return true;
    else return false;

  } else if(yk == 1) {

    if(leftSafe(x1, y1, x2, y2)) return true;
    else return false;

  } else {

    if(rightSafe(x1, y1, x2, y2)) return true;
    else return false;

  }

  return true;
}

void solve() {
  int x1, y1, x2, y2;
  inp(xk, yk, x1, y1, x2, y2);

  int cnt = getMoves();
  if(cnt == 8) {  // Inner Space
    pn
  } else if(cnt == 5) {   // Boundary
    if(canReachBoundary(x1, y1, x2, y2)) py
    else pn
  } else {  // Corner
    if(canReachCorner(x1, y1, x2, y2)) py
    else pn
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

  int t;
  cin>>t;

  while(t--) {
    solve();
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
