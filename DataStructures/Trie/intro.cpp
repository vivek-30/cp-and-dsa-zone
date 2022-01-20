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

#define MX 26

class TrieNode {
  public:
    bool isEndOfWord;
    TrieNode* child[MX];

  TrieNode(bool isEndOfWord = false) {
    this->isEndOfWord = isEndOfWord;
    f(i, 0, MX-1) {
      child[i] = null;
    }
  }
};

TrieNode* Root = new TrieNode();

void insert_key(string &key) {

  TrieNode* temp = Root;

  for(char ch: key) {
    if(temp->child[ch - 'a'] == null) {
      temp->child[ch - 'a'] = new TrieNode();
    }

    temp = temp->child[ch - 'a'];
  }

  temp->isEndOfWord = true;
}

bool search_key(string &key) {

  TrieNode* temp = Root;

  for(char ch: key) {
    if(temp->child[ch - 'a'] == null) {
      return false;
    }

    temp = temp->child[ch - 'a'];
  }

  return temp->isEndOfWord;
}

bool isEmpty(TrieNode *Root) {
  f(i, 0, MX-1) {
    if(Root->child[i]) return false;
  }

  return true;
}

TrieNode* delete_key(TrieNode* Root, string &key, int i) {
  if(!search_key(key)) {
    cout<<"Key Not Found"<<endl;
    return Root;
  }

  if(i == key.sz) {
    if(Root->isEndOfWord) {
      Root->isEndOfWord = false;
    }

    if(isEmpty(Root)) {
      delete Root;
      Root = null;
    }

    return Root;
  } 

  Root->child[key[i] - 'a'] = delete_key(Root->child[key[i] - 'a'], key, i+1);

  if(isEmpty(Root) && Root->isEndOfWord == false) {
    delete Root;
    Root = null;
  }

  return Root;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  clock_t begin = clock();

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  string key;
  int q;
  inp(q);

  f(i, 1, q) {
    char qt;
    inp(qt, key);

    if(qt == 'i') {  // Add A Key
      insert_key(key);
    } else if(qt == 's') {  // Search A Key
      cout<<(search_key(key) ? "Found" : "Not Found")<<endl;
    } else {  // Delete a Key
      Root = delete_key(Root, key, 0);
    }
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
