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

int total = 0;

void merge(vi &d, int s, int m, int e) {
  
  int i = s, j = m+1, size = e - s + 1, k = 0;
  vi res(size);

  while(i <= m && j <= e) {
    if(d[i] < d[j]) {
      res[k] = d[i];
      i++;
    } else {
      total += (m - i);
      res[k] = d[j];
    }
    k++;
  }

  while(i <= m) {
    res[k++] = d[i++];
  }

  while(j <= e) {
    res[k++] = d[j++];
  }

  f(i, 0, size-1) {
    d[s] = res[i];
    s++;
  }
}

void countInversions(vi &d, int s, int e) {
  if(s >= e) {
    return;
  }

  int m = mid(s, e);

  countInversions(d, s, m);
  countInversions(d, m+1, e);

  merge(d, s, m, e);
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
    int n;
    inp(n);

    vi d;
    int count = 0;

    f(i, 1, n) {
      int x;
      inp(x);

      if(d.empty() or d.front() > x) {
        d.insert(d.begin(), x);
      } else {
        d.push_back(x);
      }
    }
    countInversions(d, 0, d.size()-1);
    cout<<total<<endl;
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
