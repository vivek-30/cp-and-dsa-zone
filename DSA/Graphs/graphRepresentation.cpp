// Check whether a edge exists between 2 given nodes or not.
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define f(i,s,n) for(ll i = s; i < n; i++)
#define pb push_back

map<int, list<int> > g;
 
void create(int a, int b) {
  g[a].pb(b);
  g[b].pb(a);
}

bool isExists(int a, int b) {
  if(g.find(a) != g.end()) {
    list<int>::iterator it = g[a].begin();
    for(;it != g[a].end(); it++) {
      if(*it == b) 
        return true;
    }
  }

  return false;
}
 
int main() {
 
  int q, n, e, a, b;
  cin>>n>>e;

  f(i, 0, e) {
    cin>>a>>b;
    create(a, b);
  }

  cin >> q;
  while(q--) {
	  cin>>a>>b;
    if(isExists(a,b)) 
      cout<<"YES\n";
    else cout<<"NO\n";
  }
 
  return 0;
}
 