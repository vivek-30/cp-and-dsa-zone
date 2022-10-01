#include <bits/stdc++.h>
using namespace std;

#define null NULL
#define endl "\n"
#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
#define all(v) v.begin(), v.end()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef map<char, int> mci;
template <typename... T>
void inp(T &...args) { ((cin >> args), ...); }
template <typename... T>
void out(T &&...args) { ((cout << args << " "), ...); }
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for (ll i = s; i <= e; i++)
#define fr(i, s, e) for (ll i = s; i >= e; i--)
#define logarr(arr, s, e)      \
  for (int i = s; i <= e; i++) \
    cout << arr[i] << " ";     \
  cout << endl;
#define bitc(n) __builtin_popcount(n)
#define mp make_pair
#define pb push_back
#define sz size()
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int>>
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
#define fi first
#define se second
#define INF 2e18

vvll multiply(vvll A, vvll B)
{

  vvll res(4, vll(4, 0));

  f(i, 0, 3)
  {
    f(j, 0, 3)
    {
      f(k, 0, 3)
      {
        res[i][j] = (res[i][j] % mod + ((A[i][k] % mod * B[k][j] % mod) % mod) % mod) % mod;
      }
    }
  }

  return res;
}

vvll exp(vvll &fib, ll x)
{

  vvll idn(4, vll(4, 1));

  if (x == 0)
    return idn;
  if (x == 1)
    return fib;

  vvll res = multiply(fib, fib);
  if (x & 1)
  {
    return multiply(fib, multiply(res, res));
  }
  else
  {
    return multiply(res, res);
  }
}

void solve()
{
  ll n;
  inp(n);

  vvll fib(4, vll(4, 0));
  fib[0][0] = fib[0][1] = fib[1][0] = 1;
  fib[1][1] = 0;

  fib = exp(fib, n - 1);
  cout << fib[0][0] << endl;
}

ll exp(double a, ll b) {
  if(b == 0) return 1;

  ll res = exp(a, b>>1);
  if(b&1) {
    return ((ll)a%mod * ((res%mod * res%mod)%mod) %mod);
  }else return (res%mod * res%mod)%mod;
}

void solve2()
{
  ll n;
  inp(n);

  // Binet's Formula
  // ( { [( 1 + √5 ) / 2] ^ n } / √5 )

  double num = (1 + sqrt(5))/2;
  int ans = round(pow(num, n) / sqrt(5));
  cout<<ans<<endl;
}

int main()
{

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
  cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif

  return 0;
}
