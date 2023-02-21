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

// O(N * N)
void solve1(ll n, vll &arr) {

  vll dp(n, 1);

  f(i, 1, n-1) {
    fr(j, i-1, 0) {
      if(arr[j] < arr[i]) {
        dp[i] = max(dp[i], 1+dp[j]);
      }
    }
  }

  cout<<*max_element(dp.begin(), dp.end())<<endl; // it will find max element in the sequence
}

// O(N * LogN)  <binary search> (note -> it only works for non decreasing values)
void solve2(ll n, vll &arr) {
  
  vll dp(n, 1);
  
  map<int, int> m;  // (element, length)
  m[arr[0]] = 1;

  f(i, 1, n-1) {
    auto it = m.lower_bound(arr[i]+1); // first value greater than current value

    if(it != m.begin()) {
      it--;
      dp[i] = 1 + it->second;
    }

    m[arr[i]] = dp[i];
    it = m.upper_bound(arr[i]);
    
    while(it != m.end() and it->second <= dp[i]) {
        auto temp = it;
        temp++;
        m.erase(it);
        it = temp;
    }
  }

  cout<<*max_element(dp.begin(), dp.end())<<endl;
}

// O(N * LogN)  <binary search> (note -> it only works for strictly increasing values)
void solve3(ll n, vll &arr) {
  
  vll dp;
  
  f(i, 0, n-1) {
    auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
    if(it == dp.end()) {
      dp.pb(arr[i]);
    } else {
      *it = arr[i];
    }
  }

  cout<<dp.size()<<endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  vll arr(n);
  for(ll &i: arr)
    cin>>i;
  
  // solve1(n, arr);
  // solve2(n, arr);
  solve3(n, arr);

  return 0;
}
