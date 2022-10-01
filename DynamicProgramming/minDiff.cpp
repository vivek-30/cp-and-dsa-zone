#include <bits/stdc++.h>
using namespace std;

#define null NULL
#define endl "\n"
#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
typedef pair<string, string> pss;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef map<string, string> mss;
typedef map<int, string> mis;
typedef map<string, int> msi;
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, n) for (ll i = s; i <= n; i++)
#define fr(i, s, e) for (ll i = s; i >= e; i--)
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int>>
#define fi first
#define se second
#define INF 2e18

ll bsrch(ll x, int n, vll &arr)
{
  int s = 0, e = n - 1, m;

  while (s <= e)
  {
    m = mid(s, e);
    if (arr[m] == x)
      break;
    else if (arr[m] > x)
    {
      e = m - 1;
    }
    else
      s = m + 1;
  }

  return arr[m];
}

void solve(int &a, int &b, int &c, vll &arr1, vll &arr2, vll &arr3)
{
  ll ans = inf;

  f(i, 0, a - 1)
  {
    ll first = arr1[i];
    ll second = bsrch(first, b, arr2);
    ll third = bsrch(first, c, arr3);

    ans = min(ans, (abs(first - second) + abs(second - third) + abs(first - third)));
  }

  cout << ans << endl;
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, a, b, c;
  cin >> t;
  while (t--)
  {
    cin >> a >> b >> c;
    vll arr1(a), arr2(b), arr3(c);
    f(i, 0, a - 1)
      cin >> arr1[i];
    f(i, 0, b - 1)
      cin >> arr2[i];
    f(i, 0, c - 1)
      cin >> arr3[i];

    solve(a, b, c, arr1, arr2, arr3);
  }

  return 0;
}
