#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
#define ld long double
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
void out(T&&... args) { ((cout << args), ...);}
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for(int i = s; i <= e; i++)
#define fr(i, s, e) for(int i = s; i >= e; i--)
#define logarr(s, e, arr) for(int i = s; i <= e; i++) cout << arr[i] << " ";  cout << "\n";
#define bitc(n) __builtin_popcountll(n)
#define debug(x) cout << #x << " = " << x << "\n";
#define mp make_pair
#define eb emplace_back
#define sz size()
#define br "\n"
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define py cout << "YES" << "\n";
#define pn cout << "NO" << "\n";
#define fi first
#define se second
#define INF 2e18

void solve(int tc) {
  string s;
  inp(s);

  multiset<char> ms;
  map<char, set<int> > m;

  int n = s.sz;
  char ch;
  f(i, 0, n-1) {
    ch = s[i];
    m[ch].insert(i);
  }

  f(i, 0, n-1) {
    ch = s[i];
    if(ch == '0' or ch == '9') {
      ms.insert(ch);
    } else {
      int val = ch - '0';
      bool flag = 0;
      f(j, 0, val-1) {
        if(m[j+'0'].upper_bound(i) != m[j+'0'].end()) {
          val++;
          ms.insert(val + '0');
          flag = 1;
          break;
        }
      }
      if(!flag) ms.insert(ch);
    }
  }

  for(char ch: ms) {
    out(ch);
  }

  out(br);
}

void solve2(int tc) {
  string s;
  inp(s);

  multiset<char> ms;
  mci m;

  f(i, 0, s.sz-1) {
    m[s[i]] = i;
  }

  int i = 0, idx;
  for(char digit = '0'; digit <= '9'; digit++) {
    idx = m.count(digit) ? m[digit] : -1;

    if(idx == -1) continue;

    while(i <= idx) {
      if(s[i] == digit or s[i] == '9') {
        ms.insert(s[i]);
      } else ms.insert(s[i]+1);
      i++;
    }
  }

  for(char ch: ms) out(ch);
  out(br);
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

  int tc = 1;
  cin >> tc;

  f(t, 1, tc) {
    solve2(t);
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
