#define inf 1e9
#define minf -1e9
#define mod 1000000007
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


// Method 1
class Solution {
public:
  void setZeroes(vector<vector<int>>& arr) {
    int n = arr.sz, m = arr[0].sz;
    f(i, 0, n-1) {
      f(j, 0, m-1) {
        if(arr[i][j] == 0) {
          f(k, 0, n-1) {
            if(arr[k][j] != 0) arr[k][j] = inf; 
          }
          f(k, 0, m-1) {
            if(arr[i][k] != 0) arr[i][k] = inf; 
          }
        }
      }
    }
    
    f(i, 0, n-1) f(j, 0, m-1) if(arr[i][j] == inf) arr[i][j] = 0;
  }
};

// Method 2
class Solution2 {
public:
  void setZeroes(vector<vector<int>>& arr) {
    int n = arr.sz, m = arr[0].sz;
    bool isFirstColZero = false, isFirstRowZero = false;
    
    f(i, 0, n-1) {
      f(j, 0, m-1) {
        if(arr[i][j] == 0) {
          if(i == 0) isFirstRowZero = true;
          if(j == 0) isFirstColZero = true;
          arr[i][0] = arr[0][j] = 0;
        }
      }
    }
    
    f(i, 1, n-1) {
      f(j, 1, m-1) {
        if(arr[i][0] == 0 or arr[0][j] == 0) arr[i][j] = 0;
      }
    }
    
    if(isFirstRowZero) {
      f(i, 0, m-1) arr[0][i] = 0;
    }
    
    if(isFirstColZero) {
      f(i, 0, n-1) arr[i][0] = 0;
    }
  }
};