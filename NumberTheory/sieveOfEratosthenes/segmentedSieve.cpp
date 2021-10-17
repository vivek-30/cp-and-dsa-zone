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

#define MAX_SIZE 1000005

void segmented_sieve(int l, int r) {
  
  int n = r - l + 1;
  int lim = sqrt(r), start = 0, val;
  
  vector<bool> store(MAX_SIZE, true), isPrime(n, true);
  vi factors;

  for(int i = 2; i*i <= MAX_SIZE; i++) {
    if(store[i]) {
      for(int j = i*i; j <= MAX_SIZE; j += i) {
        store[j] = false;
      }
    }
  }

  f(i, 2, lim) {
    if(store[i]) {
      factors.emplace_back(i);
    }
  }

  for(int factor: factors) {
   
    val = (l/factor)*factor;
    
    if(val < l) {
      val += factor;
    }

    start = max(factor*factor, val);
    for(int j = start; j <= r; j += factor) {
      isPrime[j-l] = false;
    }
  }

  if(l == 1)
    isPrime[0] = false;

  for(int i = 0; i <= n-1; i++) {
    if(isPrime[i]) {
      cout<<i+l<<" ";
    }
  }
  cout<<endl;

}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  f(i, 1, t) {
    int l, r;
    cin>>l>>r;
    segmented_sieve(l, r);
  }

  return 0;
}
