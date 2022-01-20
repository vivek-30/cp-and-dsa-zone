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

bool found(ll x, ll y, ll z, multiset<ll> &s) {
  if(s.find(x+y) != s.end() and s.find(x+z) != s.end() and s.find(y+z) != s.end() and s.find(x+y+z) != s.end()) return true;

  return false;
}

void solve() {
  vll arr(7);
  multiset<ll> s;
  f(i, 0, 6) inp(arr[i]), s.insert(arr[i]);

  f(i, 0, 6) {
    f(j, i+1, 6) {
      f(k, j+1, 6) {
        multiset<ll> temp = s;
        temp.erase(temp.find(arr[i]));
        temp.erase(temp.find(arr[j]));
        temp.erase(temp.find(arr[k]));
        if(found(arr[i], arr[j], arr[k], temp)) {
          out(arr[i], " ", arr[j], " ", arr[k], '\n');
          return;
        }
      }
    }
  }

  out(arr[0], " ", arr[1], " ", arr[2], '\n');
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
