#include<iostream>
using namespace std;

#define null NULL
#define inf INT_MAX
#define minf INT_MIN
#define ll long long int
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define vi vector<int>
#define mii map<int, int>
#define vvi vector<vector<int> >
#define pii pair<int, int>
#define mid(l, r) (l + (r - l) / 2)
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define f(i,s,n) for(ll i = s; i < n; i++)

int res[100];

// Recursive Approach W/O DP.
int fib1(int n) {
  
  if(n == 0 or n == 1)
    return n;

  return fib1(n-1) + fib1(n-2);
}

// Top Down DP (Memoization).
int fib2(int n) {
  
  if(res[n] != inf)
    return res[n];

  if(n == 0 or n == 1)
    return n;

  res[n] = fib2(n - 1) + fib2(n - 2);
  return res[n];
}

// Bottom Up DP (Tabulation).
int fib3(int n) {
  
  if(res[n] != inf)
    return res[n];

  res[0] = 0;
  res[1] = 1;

  f(i, 2, n)
    res[i] = res[i - 1] + res[i - 2];

  return res[n - 1];
}

// Iterative Approach.
int fib4(int n) {
  
  if(n == 0 or n == 1)
    return n;

  int first = 0, second = 1;
  int ans = first + second;
  
  f(i, 2, n) {
    first = second;
    second = ans;
    ans = first + second;
  }

  return ans;
}

int main() {

  int n;
  cin>>n;

  f(i, 0, sizeof(res))
    res[i] = inf;

  f(i, 0, n)
    cout<<fib3(i)<<" ";
  cout<<endl;

  return 0;
}
