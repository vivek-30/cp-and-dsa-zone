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

char d;

ll convert(string num, string t) {
  
  ll a = 0, b = 0;

  a = stoi(num);
  b = stoi(t);

  return (b - a);
}

ll solve(string num) {
  
  string t = num;
  int n = t.length(), idx = -1;
  f(i, 0, n-1) {
    if(t[i] == d) {
      idx = i;
      break;
    }
  }

  if(idx == -1) {
    return 0;
  }

  if(d == '0') {
    f(i, idx, n-1) {
      t[i] = '1';
    }
  } else if(d == '9') {
    if(idx == 0 or (idx == 1 && t[0] == '8')) {
      string k(n+1, '0');
      k[0] = '1';
      return convert(num, k);
    }else if(t[idx-1] == '8') {
      
      f(i, (idx), n-1) {
        t[i] = '0';
      }

      int j = idx-1, val;
      while(j >= 0 && t[j] == '8') {
        t[j] = '0';
        j--; 
      }

      if(j < 0) {
        t = '1' + t;
      } else {
        val = (t[j] - '0');
        val += 1;
        t[j] = (val + '0');
      }
    }
    else {
      f(i, idx, n-1) {
        t[i] = '0';
      }
      int val = (t[idx-1] - '0');
      val += 1;
      t[idx-1] = (val + '0');
    }
  } else {
    f(i, idx+1, n-1) {
      t[i] = '0';
    }
    int val = (t[idx] - '0');
    val += 1;
    t[idx] = (val + '0');
  }

  return convert(num, t);
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
    string n;
    inp(n, d);

    cout<<solve(n)<<endl;
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
