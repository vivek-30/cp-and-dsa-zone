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

string convertToString(int val, int n) {

  string s = "";

  f(i, 0, n-1) {
    s = ((val & (1<<i)) ? '1' : '0') + s;
  }

  return s;
}

// Faster
void solve2() {
  
  bool *visited = new bool[(1<<16)+5]();
  
  int n;
  inp(n);

  string s(n, '0');
  int val = 0, i = 1, k = (1<<n), j;
  visited[val] = true;
  cout<<s<<endl;

  while(i < k) {
    
    j = 0;
    
    while(visited[val^(1<<j)]) j++;

    val = val^(1<<j);
    visited[val] = true;
    cout<<convertToString(val, n)<<endl;
    
    i++;
  }
  
  delete[] visited;
}

void solve() {
  int n;
  inp(n);
  ump<string, bool> m;

  string s(n, '0');

  int i = 1, k = (1<<n);
  m[s] = true;
  cout<<s<<endl;

  while(i < k) {
    fr(pos, n-1, 0) {
      s[pos] = (s[pos] == '0') ? '1' : '0';
      if(m[s] == false) {
        break;
      }
      s[pos] = (s[pos] == '0') ? '1' : '0';
    }

    m[s] = true;
    cout<<s<<endl;
    i++;
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

  solve2();

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
