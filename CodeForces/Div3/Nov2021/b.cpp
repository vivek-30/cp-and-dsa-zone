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

int getAns1(int x, int y) {
  int s = 1, e = y, m, ans = 0;

  while(s <= e) {
    m = mid(s, e);

    if(3*m <= x) {
      ans = m;
      s = m+1;
    } else {
      e = m-1;
    }
  }

  return ans;
}

int getAns2(int x, int y) {
  int s = 1, e = y, m, ans = 0;

  if(y == 1) return 1;

  while(s <= e) {
    m = mid(s, e);

    if(2*m <= y && 2*m <= x) {
      ans = m;
      s = m+1;
    } else {
      e = m-1;
    }
  }

  return ans;
}

void solve() {
  int a, b;
  inp(a, b);

  int ans = 0;
  if(a == 0 or b == 0 or a+b <= 3) ans = 0;
  else if(a == b) ans = a >> 1; 
  else {
    ans = max(getAns2(max(a, b), min(a, b)), getAns1(max(a, b), min(a, b)));
  }

  out(ans, '\n');
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
