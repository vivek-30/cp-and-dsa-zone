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

void solve(int bag1, int bag2, int bag3, int checkInCap, int carryCap)
{
  if (bag1 <= carryCap and (bag2 + bag3) <= checkInCap)
  {
    cout << "YES" << endl;
  }
  else if (bag2 <= carryCap and (bag1 + bag3) <= checkInCap)
  {
    cout << "YES" << endl;
  }
  else if (bag3 <= carryCap and (bag1 + bag2) <= checkInCap)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  f(i, 1, t)
  {
    int bag1, bag2, bag3, checkInCap, carryCap;
    cin >> bag1 >> bag2 >> bag3 >> checkInCap >> carryCap;

    solve(bag1, bag2, bag3, checkInCap, carryCap);
  }

  return 0;
}
