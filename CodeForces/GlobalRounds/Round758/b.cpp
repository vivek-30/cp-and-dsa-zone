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

void solve() {
  int n, a, b;
  inp(n, a, b);

  if(n%3 == 0 && (a > n/3 or b > n/3)) out("-1\n");
  else if(n%3 == 1 && (a > n/3 + 1 or b > n/3 + 1) or (a >= n/3 + 1 && b >= n/3 + 1)) out("-1\n");
  else if(n%3 == 2 && (a > n/3 + 3 or b > n/3 + 3) or (a >= n/3 + 2 && b >= n/3 + 2)) out("-1\n");
  else {

    vi res;
    vi::iterator it;
    res.pb(1);
    bool flag = true;

    if(a <= b) {
      f(i, 2, n) {
        if(a == 0) break;
        if(flag) {
          res.pb(i);
        } else {
          it = res.rbegin();
          it--;
          res.insert(it, i);
        }
        flag = !flag;
        a--;
      }
    } else {
       f(i, 2, n) {
        if(b == 0) break;
        if(flag) {
          res.pb(i);
        } else {
          it = res.rbegin();
          it--;
          res.insert(it, i);
        }
        flag = !flag;
        b--;
      }
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
