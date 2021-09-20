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

// s[i] == 1 means player do not want to loose any match
// s[i] == 2 means player want to win atleast one match

void solve(string &s, int n) {
  
  vector<vector<char> > arr(n, vector<char> (n, '='));
  
  f(i, 0, n-1) {
    arr[i][i] = 'X';
  }

  vi players;

  f(i, 0, n-1) {
    if(s[i] == '2') 
      players.pb(i);
  }

  int size = players.size();
  if(size == 1 || size == 2) {
    cout<<"No"<<endl;
    return;
  }

  int a, b = 0;

  f(i, 0, size-1) {
    a = players[i];
    b = players[(i+1)%size];
    arr[a][b] = '+';
    arr[b][a] = '-';
  }

  cout<<"Yes"<<endl;
  f(i, 0, n-1) {
    f(j, 0, n-1) {
      cout<<arr[i][j];
    }
    cout<<endl;
  }
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

  ll t;
  cin >> t;
  f(i, 1, t) {
    int n;
    cin>>n;
    string s;
    cin>>s;

    solve(s, n);
  }

  #ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
