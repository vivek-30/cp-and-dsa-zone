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
typedef vector<vector<int> > vvi;
typedef vector<pii > vii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef map<string, string> mss;
typedef map<int, string> mis;
typedef map<string, int> msi;
#define mid(l, r) (l + (r - l) / 2)
#define f(i,s,n) for(ll i = s; i <= n; i++)
#define fr(i,s,n) for(ll i = e; i >= s; i--)
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define fi first
#define se second
#define INF 2e18

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin>>n;

  vi coins(n);
  vi v;
  for(int &i: coins)
    cin>>i;

  set<int> s;
  for(int coin: coins) {
    for(auto it = s.begin(); it != s.end(); it++) {
      v.push_back(((*it)+coin));
    }
    for(int i: v)
      s.insert(i);
    v.clear();
    s.insert(coin);
  }

  cout<<s.size()<<endl;
  for(auto it = s.begin(); it != s.end(); it++) {
    cout<<*it<<" ";
  }

  cout<<endl;

  return 0;
}
