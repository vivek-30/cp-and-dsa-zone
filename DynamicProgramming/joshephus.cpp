#include<bits/stdc++.h>
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
#define f(i,s,n) for(ll i = s; i <= n; i++)
#define fr(i,s,e) for(ll i = s; i >= e; i--)

int solve(int &n) {

  // Approach => find (2^i + l) as close as n
  // where i is power of 2 so, 2^i can be exaclty equal to n in that case l = 0
  // l = remaining difference of 2^i and n. 
  

  // solution => after finding l return (2*l + 1) which is our desired result  [Note - l can be 0 as well]
  int i = 0;
  
  while((1<<i) < n) {
    i++;
  }

  if(1<<i == n) {
    return 1;   // as l = 0
  }
  else {
    i--;
    int l = (n - (1<<i));
    return (2*l + 1);
  }

  return -1;
}

int main() {

  int n;
  cin>>n;

  cout<<solve(n)<<endl;

  return 0;
}
