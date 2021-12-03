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

vi g[200005];
vi indegree(200005, 0);
set<int> s;

void topo(int src, int n) {

	int cnt = 0;
	vi res;
	
	while(not s.empty()) {
		int curr = (*s.begin());
		res.pb(curr);
		cnt++;

		s.erase(s.begin());

		for(int child: g[curr]) {
			indegree[child]--;
			if(indegree[child] == 0)
				s.insert(child);
		}
	}

	if(cnt != n) {
		cout<<"-1"<<endl;
	} else {
		for(int i: res) {
			cout<<i<<" ";
		}
		cout<<endl;
	}
	
}

void solve() {
  int n, m;
	inp(n, m);

	f(i, 1, m) {
		int x,y;
		inp(x, y);
		g[x].pb(y);
		indegree[y]++;
	}

	f(i, 1, n) {
		if(indegree[i] == 0) {
			s.insert(i);
		}
	}

	topo(*(s.begin()), n);
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
