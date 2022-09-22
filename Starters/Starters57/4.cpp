#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define inf 2e18
#define minf -2e18
#define yes cout << "YES" << "\n";
#define no cout << "NO" << "\n";
#define pii pair<ll, ll>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vi>
#define mid(s, e) (s + (e - s) / 2)
#define all(v) v.begin(), v.end()
#define rep(i, s, e) for(int i = s; i <= e; i++)
#define reprev(i, s, e) for(int i = s; i >= e; i--)
template<typename... T>
void input(T&... args) { ((cin >> args), ...);}
template<typename... T>
void print(T&&... args) { ((cout << args), ...);}
#define debug(x) cout << #x << " = " << x << '\n';
#define bitcount(x) __builtin_popcountll(x)
#define sz size()

void solve() {
  int n;
  string s;
  input(n, s);

  vi arr(12, 0);
  for(char ch: s) {
    if(ch == '+') arr[10]++;
    else if(ch == '-') arr[11]++;
    else arr[ch - '0']++;
  }

  string ans = "";
  char ch;
  int val = (arr[10] + arr[11]), i = 9;
  int cnt = n - val;
  while(cnt != val) {
    while(arr[i] > 0 && cnt != val) {
      ch = i + '0';
      ans += ch;
      arr[i]--;
      cnt--;
    }
    if(cnt != val) i--;
  }

  while(arr[10]) {
    while(arr[i] > 0 && arr[10] > 0) {
      ans += '+';
      ch = i+'0';
      ans += ch;
      arr[10]--;
      arr[i]--;
    }
    if(arr[10]) i--;
  }

  while(arr[11]) {
    while(arr[i] > 0 && arr[11] > 0) {
      ans += '-';
      ch = i+'0';
      ans += ch;
      arr[11]--;
      arr[i]--;
    }
    if(arr[11]) i--;
  }

  print(ans, '\n');
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int t = 1;
  cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}
