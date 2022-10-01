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
#define fi first
#define se second
#define INF 2e18

ll exp(ll a, ll b) {
  
  ll res = 1;
  
  while(b) {
    if(b&1) res = (res*a)%mod;
    b >>= 1;
    a = (a*a)%mod;
  }

  return res;
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

  ll n, sum = 0, curr = 1;
  inp(n);

  f(j, 1, n) {
    vii res;

    int num = j;

    if(num == 1) {
      sum += num;
      continue;
    }

    int count = 0;
    while(num%2 == 0) {
      count++;
      num >>= 1;
    }

    if(count > 0) {
      res.pb(mp(2, count));
    }

    for(int i = 3; i*i <= num; i += 2) {
      if(num%i == 0) {
        count = 0;
        while(num%i == 0) {
          count++;
          num /= i;
        }
        res.pb(mp(i, count));
      }
    }

    if(num > 1) {
      res.pb(mp(num, 1));
    }

    for(auto i: res) {
      curr = (curr * ((exp(i.fi, i.se + 1) - 1) * exp(i.fi - 1, mod - 2)) % mod) % mod;
    }

    sum = (sum + curr) % mod;
    curr = 1;
  }

  cout<<sum<<endl;

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
