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

void build(int s, int e, int idx, vi &arr, vi &tree) {

  if(s == e) {  // Leaf Node
    tree[idx] = arr[s];
    return;
  }

  int m = mid(s, e);
  build(s, m, 2*idx, arr, tree); // Build Left Part OF Tree
  build(m+1, e, 2*idx+1, arr, tree); // Build Right Part OF Tree

  tree[idx] = tree[2*idx] + tree[2*idx+1];
}

int query(int s, int e, int idx, int qs, int qe, vi &tree) {// qs and qe are also index based not number based

   // Complete Redundant
  if(qe < s or qs > e) {
    return 0;
  }

  // Complete Overlap
  if(s >= qs and e <= qe) {   // (s, e) represents a node which lies inside our required query
    return tree[idx];
  }

  // Partial Overlap
  int m = mid(s, e);
  return query(s, m, 2*idx, qs, qe, tree) + query(m+1, e, 2*idx+1, qs, qe, tree);
}

void update(int s, int e, int tree_idx, int arr_idx, int val, vi &arr, vi &tree) {

  if(s == e) {
    arr[arr_idx] = val;
    tree[tree_idx] = val;
    return;
  }

  int m = mid(s, e);
  if(arr_idx > m) {
    update(m+1, e, 2*tree_idx+1, arr_idx, val, arr, tree);
  }
  else {
    update(s, m, 2*tree_idx, arr_idx, val, arr, tree);
  }

  tree[tree_idx] = tree[2*tree_idx] + tree[2*tree_idx + 1];
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin>>n;

  vi arr(n);
    for(int &i: arr)
    cin>>i;

  vi tree(4*n, 0);
  build(0, n-1, 1, arr, tree);
  
  cout<<query(0, n-1, 1, 3, 4, tree)<<endl;
  cout<<query(0, n-1, 1, 1, 4, tree)<<endl;
  
  update(0, n-1, 1, 2, 8, arr, tree);
  cout<<query(0, n-1, 1, 2, 2, tree)<<endl;
  
  update(0, n-1, 1, 0, 4, arr, tree);
  cout<<query(0, n-1, 1, 0, 4, tree)<<endl;

  return 0;
}
