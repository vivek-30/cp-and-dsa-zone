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
#define sz size()
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define fi first
#define se second
#define INF 2e18
 
bool check(int i, ll sum, vi &res, int n) {
  if(sum == 0) return true;
 
  if(sum < 0 or i > n) return false;
 
  if(check(i+1, sum, res, n)) return true;
 
  if(check(i+1, sum - i, res, n)) {
    res.pb(i);
    return true;
  }
 
  return false;
}
 
void solve() {
  int n;
  inp(n);
 
  ll sum = (n*(n+1))/2;
  if(sum&1) pn
  else {
    vi res;
    if(check(1, sum/2, res, n)) {
      py 
      int x = res.size(), y, j = 0;
      cout<<x<<endl;
      f(i, 0, x-1) {
        cout<<res[i]<<" ";
      }
      cout<<endl;
 
      sort(all(res));
 
      y = n - x;
      cout<<y<<endl;
      f(i, 1, n) {
        if(i == res[j]) {
          j++;
          continue;
        }
        else cout<<i<<" ";
      }
      cout<<endl;
    }
  }
}

void solve2() {
  int n;
  inp(n);

  ll sum = (n*(n+1))/2;
  if(sum&1) {
    pn
    return;
  }

  sum >>= 1;

  vi s1, s2;
  fr(i, n, 1) {
    if(i <= sum) {
      s1.pb(i);
      sum -= i;
    } else {
      s2.pb(i);
    }
  }

  py
  cout<<s1.sz<<endl;
  logarr(s1, 0, s1.sz - 1);

  cout<<s2.sz<<endl;
  logarr(s2, 0, s2.sz - 1);
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
 
  solve2();
 
  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif
 
  return 0;
}
