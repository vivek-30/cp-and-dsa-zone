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

char field[11][20];
int n, m, k;

bool mark(int i, int j) {

  int curr = 0;
  int x = i, y = j;


  while(i >= 0 && j >= 0 && field[i][j] == '*') {
    if(i-1 >= 0 && j+1 >= 0 && j+1 < m && field[i-1][j+1] == '*') {
      field[i][j] = '*';
    } else {
      field[i][j] = '$';
    }
    i--;
    j--;
    curr++;
  }

  field[x][y] = '$'; 

  if(curr-1 < k)
    return false;

  curr = 0;

  i = x+1;
  j = y+1;

  while(i >= 0 && j >= 0 &&  i < m && j < m && field[i][j] == '*') {
    if(i-1 >=0 && j-1 >= 0 && field[i-1][j-1] == '*') {
      field[i][j] = '*';
    } else {
      field[i][j] = '$';
    }
    i--;
    j++;
    curr++;
  }

  if(curr-1 < k)
    return false;
  
  return true;
}

bool solve(int i, int j) {

  fr(i, n-1, 0) {
    fr(j, m-1, 0) {
      if(field[i][j] == '*') {
        if(mark(i, j) == false)
          return false;
      }
    }
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
    inp(n, m, k);

    f(i, 0, n-1)
      f(j, 0, m-1)
        cin>>field[i][j];

    if(solve(n-1, m-1))
      py
    else pn

    f(i, 0, n-1) {
      f(j, 0, m-1) {
        cout<<field[i][j]<<" ";
      }
      cout<<endl;
    }
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
