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

map<char, int> m;

bool cmp(string &s, string &t) {

  f(i, 0, min(s.length(), t.length()) - 1) {
    if(m[s[i]] == m[t[i]])
      continue;
    
    return m[s[i]] < m[t[i]];
  }

  return s.length() <= t.length();
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;

  string x, s;
  cin>>x;

  cin>>n;
  vector<string> arr(n);

  f(i, 0, x.length()) {
    m[x[i]] = i+1;
  }

  f(i, 0, n-1) {
    cin>>s;
    arr[i] = s;
  }

  sort(arr.begin(), arr.end(), cmp);

  f(i, 0, n-1) {
    cout<<arr[i]<<endl;
  }

  return 0;
}
