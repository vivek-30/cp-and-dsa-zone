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
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define fi first
#define se second
#define INF 2e18

vi arr, helper, FT;
int mx = -1;

int query(int i) {
  int sum = 0;
  for(; i>0; i -= i&(-i))
    sum += FT[i];

  return sum;
}

void update(int i, int val) {
  for(; i <= mx; i += i&(-i))
    FT[i] += val;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  clock_t begin = clock();

  int n;
  inp(n);
  
  arr.resize(n), helper.resize(n);
  f(i, 0, n-1) inp(arr[i]);

  vi temp = arr;
  sort(all(temp));

  f(i, 0, n-1) {
    int val = lower_bound(all(temp), arr[i]) - temp.begin() + 1;
    helper[i] = val;
    mx = max(mx, val);
  }

  FT.resize(mx + 1);

  int ans = 0;
  fr(i, n-1, 0) {
    ans += query(helper[i]-1);
    update(helper[i], 1);
  }

  cout<<ans<<endl;

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
