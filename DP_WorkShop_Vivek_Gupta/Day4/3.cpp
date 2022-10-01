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
#define py cout << "Yes" << "\n";
#define pn cout << "No" << "\n";
#define fi first
#define se second
#define INF 2e18

void solve(int tc) {
  int total_words;
  string s;
  cin>>total_words>>s;

  set<string> words;
  f(i, 1, total_words) {
    string ss;
    cin>>ss;
    words.insert(ss);
  }

  int n = s.sz;

  vb dp(n+1, 0);
  dp[0] = 1;

  f(i, 1, n) {
    string curr = "";
    fr(j, i, 1) {
      curr = s[j-1] + curr;
      if(words.count(curr) && dp[j-1]) dp[i] = 1;
    }
  }

  if(dp[n]) py
  else pn
}

bool getAns(string s, set<string> &words, map<string, bool> &dp) {
  if(words.count(s)) {
    return true;
  }

  if(dp.count(s)) return dp[s];

  string str = "";
  f(i, 0, s.sz-1) {
    str += s[i];
    if(words.count(str) && getAns(s.substr(i+1), words, dp)) {
      return dp[s] = true;
    }
  } 

  return dp[s] = false;
}

void solve2(int tc) {
  int total_words;
  string s;
  cin>>total_words>>s;

  set<string> words;
  f(i, 1, total_words) {
    string ss;
    cin>>ss;
    words.insert(ss);
  }
  
  map<string, bool> dp;
  if(getAns(s, words, dp)) py
  else pn
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
