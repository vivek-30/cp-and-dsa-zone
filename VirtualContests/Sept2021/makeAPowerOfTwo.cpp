#include <bits/stdc++.h>
using namespace std;

#define null NULL
#define endl "\n"
#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,string> pis;
typedef pair<string,int> psi;
typedef pair<string,string> pss;
typedef vector<pii > vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vi > vvi;
typedef vector<vll > vvll;
typedef map<int, int> mii;
typedef map<string, string> mss;
typedef map<int, string> mis;
typedef map<string, int> msi;
#define mid(l, r) (l + (r - l) / 2)
#define f(i,s,n) for(ll i = s; i <= n; i++)
#define fr(i,s,e) for(ll i = s; i >= e; i--)
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define fi first
#define se second
#define INF 2e18

int solve(string s1, string s2) {

  int n = s1.length(), m = s2.length();

  int i = 0, j = 0, common = 0;
  while(i < n and j < m) {
    if(s1[i] == s2[j]) {
      j++;
      common++;
    }
    i++;
  }

  return ((n - common) + (m - common)); // operation of removing non matching no. + adding no common no.
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  f(i, 1, t) {
    string n;
    cin>>n;

    int ans = inf;
    for(ll j = 1; j<= (ll)INF; j *= 2) {
      ans = min(ans, solve(n, to_string(j)));
    }

    cout<<ans<<endl;
  }

  return 0;
}
