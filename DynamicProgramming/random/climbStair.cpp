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

int climb(int n) {

  if(n == 1) 
    return 1;
    
  int dp[n+1];
    
  dp[1] = 1;
  dp[2] = 2;
  
  for(int i=3; i<=n; i++)
      dp[i] = dp[i-1] + dp[i-2];
  
  return dp[n];
}

int climb2(int n, int dp[]) {
  if(n == 0) return 1;
  else if(n < 0) return 0;

  if(dp[n] != minf) 
    return dp[n];

  return dp[n] = climb2(n-1, dp) + climb2(n-2, dp);
}

int main() {

  int n;
  cout<<"Enter a number"<<endl;
  cin>>n;

  int dp[n+1];
  f(i, 0, n+1)
    dp[i] = minf;

  cout<<climb(n)<<endl;
  cout<<climb2(n, dp)<<endl;

  return 0;
}
