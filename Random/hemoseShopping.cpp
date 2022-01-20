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
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define fi first
#define se second
#define INF 2e18

bool isSorted(vi &arr, int n) {
  f(i, 1, n-1) {
    if(arr[i] < arr[i-1]) return false;
  } 

  return true;
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

  int t;
  cin>>t;

  while(t--) {
    int n, x;
    inp(n, x);

    vi arr(n);
    f(i, 0, n-1) inp(arr[i]);

    if(x <= (n/2)) {
      py
    } else if(n == x) {
      if(isSorted(arr, n)) py
      else pn
    } else {
      vi temp;
      f(i, 0, (n-x-1)) {
        temp.pb(arr[i]);
      }
      int j = temp.size(), i = n-1;
      while(j) {
        temp.pb(arr[i--]);
        j--;
      }

      sort(all(temp));
      f(i, 0, (temp.size()/2) - 1) {
        arr[i] = temp[i];
      }
      j = n-1;
      fr(i, temp.size()-1, temp.size()/2) {
        arr[j--] = temp[i];
      }

      if(isSorted(arr, n)) py
      else pn
    }
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
