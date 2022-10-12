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
void output(T&&... args) { ((cout << args), ...);}
#define debug(x) cout << #x << " = " << x << '\n';
#define bitcount(x) __builtin_popcountll(x)
#define sz size()

void solve() {
  int n;
  input(n);

  vi arr(n);
  rep(i, 0, n-1) input(arr[i]);

  int i = 0, j = n-1, flag = 1, curr;
  while(i < j) {
    if(arr[i] != arr[j]) {
      flag = 0;
      break;
    }
    i++, j--;
  }

  if(flag) {
    output("0\n");
    return;
  }
  
  int diff = arr[n-1] - arr[0];

  if(diff < 0) {
    output("-1\n");
    return;
  }

  i = 1, j = n-2;
  while(i <= j) {
    curr = arr[j] - arr[i];
    if(curr < 0 or curr > diff) {
      output("-1\n");
      return;
    }
    diff = curr;
    i++, j--;
  }

  output(arr[n-1] - arr[0], '\n');
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
