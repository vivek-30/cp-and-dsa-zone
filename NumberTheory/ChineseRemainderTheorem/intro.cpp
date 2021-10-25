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

int P = 1;

struct Info {
  int g, x1, y1; 

  Info(int _g, int _x1, int _y1) {
    g = _g;
    x1 = _x1;
    y1 = _y1;
  }
};

Info Inverse(int a, int b) {
  
  if(b == 0) {
    Info i(a, 1, 0);
    return i;
  }

  Info res = Inverse(b, a%b);
  Info ans(res.g, res.y1, (res.x1 - (a/b)*res.y1));

  return ans;
}

void solve() {
  int n;
  inp(n);

  vi nums(n), rem(n);
  f(i, 0, n-1) {
    inp(nums[i], rem[i]);
    P *= nums[i];
  }

  ll ans = 0;
  f(i, 0, n-1) {
    Info res = Inverse(P/nums[i], nums[i]);
    int x = (res.x1 % nums[i] + nums[i]) % nums[i];
    ans += (rem[i] * P/nums[i] * x);
  }

  ans %= P;
  cout<<ans<<endl;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  clock_t begin = clock();

  solve();

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
