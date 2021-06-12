#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define mid(l, r) (l + (r - l) / 2)
#define ll long long int
#define f(i,s,n) for(ll i = s; i < n; i++)
#define inf 2e18

bool isPossible(int arr[], ll n, ll c, ll m) {
  ll i, pos=0,curr=1;
  f(i, 1, n){
    if(arr[i]-arr[pos]>=m){
      curr++;
      pos=i;
    }

    if(curr>=c) return true;
  }

  return false;
}
 
ll solve(int stalls[], ll n, ll c) {
  ll s=1,e=stalls[n-1],m,res=inf;
  while(s<=e){
    m=mid(s,e);
    if(isPossible(stalls, n, c, m)){
      res=m;
      s=m+1;
    } else {
      e=m-1;
    }
  }

  return res;
}
 
int main() {
 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  ll t;
  cin >> t;
  for(ll i = 1; i <= t; i++) {
    ll n, c, j;
    cin>>n>>c;
    int stalls[n];

    f(j,0,n)
      cin>>stalls[j];
    
    sort(stalls, stalls+n);
    cout<<solve(stalls, n, c)<<endl;
  }
 
  return 0;
}
 