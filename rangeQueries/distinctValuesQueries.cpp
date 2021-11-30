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
void out(T&&... args) { ((cout << args), ...);}
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for(ll i = s; i <= e; i++)
#define fr(i, s, e) for(ll i = s; i >= e; i--)
#define logarr(s, e, arr) for(int i = s; i <= e; i++) cout<<arr[i]<<" "; cout<<endl;
#define bitc(n) __builtin_popcount(n)
#define mp make_pair
#define pb push_back
#define sz size()
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define fi first
#define se second
#define INF 2e18

int n, qq, sqt;

class Querie {
  public: 
    int l, r, idx;
    
    Querie() {
      l = r = idx = 0;
    }
};

bool cmp(Querie &x, Querie &y) {
  if(x.l/sqt == y.l/sqt) return (x.l/sqt & 1 ? x.r/sqt < y.r/sqt : x.r/sqt > y.r/sqt);
  return x.l/sqt < y.l/sqt;
}

void include(vi &freq, int val, int &ans) {
  if(freq[val] == 0) {
    ans++;
  }
  freq[val]++;
}

void exclude(vi &freq, int val, int &ans) {
  freq[val]--;
  if(freq[val] == 0) {
    ans--;
  }
}

vi getQueriesAns(vi &arr, vector<Querie> &q) {
  vi res(qq), freq(n+1, 0);

  int curr_l = q[0].l - 1, curr_r = q[0].l - 1, ans = 1, l, r;

  freq[arr[curr_l]]++;

  f(i, 0, qq-1) {
    l = q[i].l - 1, r = q[i].r - 1;

    while(curr_l > l) {
      curr_l--;
      include(freq, arr[curr_l], ans);
    }

    while(curr_r < r) {
      curr_r++;
      include(freq, arr[curr_r], ans);
    }

    while(curr_l < l) {
      exclude(freq, arr[curr_l], ans);
      curr_l++;
    }

    while(curr_r > r) {
      exclude(freq, arr[curr_r], ans);
      curr_r--;
    }

    res[q[i].idx] = ans;
  }

  return res;
}

void solve() {
  inp(n, qq);

  vi arr(n);
  vector<Querie> store(qq);

  sqt = sqrtl(n);

  f(i, 0, n-1) inp(arr[i]);

  f(i, 0, qq-1) {
    inp(store[i].l, store[i].r);
    store[i].idx = i;
  }

  mii m;
  vi modified_array(n);

  int val = 1;
  f(i, 0, n-1) {
    if(m.find(arr[i]) == m.end()) {
      m[arr[i]] = val;
      modified_array[i] = val++;
    } else {
      modified_array[i] = m[arr[i]];
    }
  }

  sort(all(store), cmp);
  vi res = getQueriesAns(modified_array, store);

  for(int &i: res) out(i, '\n');
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

  solve();

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
