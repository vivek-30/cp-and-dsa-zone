#include <bits/stdc++.h>
using namespace std;

#define inf 2e18
#define minf -2e18
#define mod 1000000007
#define int long long int
#define ld long double
#define all(v) v.begin(), v.end()
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<char, int> mci;
template<typename... T>
void inp(T&... args) { ((cin >> args), ...);}
template<typename... T>
void out(T&&... args) { ((cout << args), ...);}
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for(int i = s; i <= e; i++)
#define fr(i, s, e) for(int i = s; i >= e; i--)
#define logarr(s, e, arr) for(int i = s; i <= e; i++) cout << arr[i] << " ";  cout << "\n";
#define bitc(n) __builtin_popcountll(n)
#define debug(x) cout << #x << " = " << x << "\n";
#define mp make_pair
#define eb emplace_back
#define sz size()
#define br "\n"
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define py cout << "YES" << "\n";
#define pn cout << "NO" << "\n";
#define fi first
#define se second

int res = 0;

void merge(int arr[],int l,int mid,int r){
  int* temp = new int[r-l+1];
  int i=l,j=mid+1;
  int t=0;

  while(i<=mid && j<=r){
    if(arr[i]<=arr[j]){
      temp[t++]=arr[i++];
    }
    else{
      temp[t++]=arr[j++];
      res+=(mid-i+1);
    }
  }
  while(i<=mid){
    temp[t++]=arr[i++];
  }
  while(j<=r){
    temp[t++]=arr[j++];
  }
  t=0;
  for(int i=l;i<=r;i++){
    arr[i]=temp[t++];
  }
  delete [] temp;
}


void merge_sort(int arr[],int l,int r){
  int res = 0;
  if(l>=r){
    return;
  }
  
  int mid=(l+r)/2;
  
  merge_sort(arr,l,mid);
  merge_sort(arr,mid+1,r);
  
  merge(arr,l,mid,r);
}

void solve(int tc) {
  int n;
  inp(n);

  int arr[n], temp[n];
  f(i, 0, n-1) {
    inp(arr[i]);
    temp[i] = arr[i];
  }

  int o = -1, z = -1;
  merge_sort(arr, 0, n-1);

  int ans = res;
  res = 0;
  fr(i, n-1, 0) {
    if(temp[i] == 1) {
      o = i;
      break;
    }
  }

  f(i, 0, n-1) {
    if(temp[i] == 0) {
      z = i;
      break;
    }
  }

  if(z != -1) {
    f(i, 0, n-1) arr[i] = temp[i];
    arr[z] = 1;
    merge_sort(arr, 0, n-1);
    ans = max(ans, res);
    res = 0;
  }

  if(o != -1) {
    f(i, 0, n-1) arr[i] = temp[i];
    arr[o] = 0;
    merge_sort(arr, 0, n-1);
    ans = max(ans, res);
    res = 0;
  }

  out(ans, br);
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  clock_t begin = clock();

  int tc = 1;
  cin >> tc;

  f(t, 1, tc) {
    solve(t);
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
