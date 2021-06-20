#include <bits/stdc++.h>
using namespace std;
 
#define null NULL
#define inf INT_MAX
#define minf INT_MIN
#define ll long long int
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,string> pis;
typedef pair<string,int> psi;
typedef pair<string,string> pss;
typedef vector<pii > vii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef map<string, string> mss;
typedef map<int, string> mis;
typedef map<string, int> msi;
#define mid(l, r) (l + (r - l) / 2)
#define f(i,s,n) for(ll i = s; i < n; i++)
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define pq priority_queue
#define fi first
#define se second
#define INF 2e18
 
pll findMinAndMaxDiff(vi arr) {
  
  if(arr.size() <= 0) return {-1, -1};

  pll res;
  sort(arr.begin(), arr.end());

  // Find Maximum Difference.
  int i = 0, j = arr.size() - 1;
  ll ans = 0;

  while(i < j) {
    ans += abs(arr[i++] - arr[j--]);
  }
  
  res.fi = ans;
  ans = 0;

  // Find Minimum Difference.
  for(i = 1; i < arr.size(); i += 2) {
    ans += abs(arr[i - 1] - arr[i]);
  }

  res.se = ans;
  ans = 0;

  return res;
}
 
int main() {
  
  vi arr {12, -3, 10, 0};
  
  pll res = findMinAndMaxDiff(arr);
  cout<<"Maximum = "<<res.fi<<" and Minimun = "<<res.se<<endl;
  
  return 0;
}
  