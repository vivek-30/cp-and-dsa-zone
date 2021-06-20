#include <bits/stdc++.h>
using namespace std;

#define null NULL
#define inf INT_MAX
#define minf INT_MIN
#define ll long long int
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<string,int> psi;
typedef pair<string,string> pss;
typedef vector<pii > vii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef map<string, string> mss;
typedef map<int, string> mis;
typedef map<string, int> msi;
#define mid(l, r) (l + (r - l) / 2)
#define f(i,s,n) for(ll i = s; i < n; i++)
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define pq priority_queue
#define fi first
#define se second
#define INF 2e18

ll current;

struct Travel {
  int petrol, dist;
  Travel() {
    petrol = dist = 0;
  }

  Travel(int _petrol, int _dist) {
    petrol = _petrol;
    dist = _dist;
  } 
};

bool cmp(Travel a, Travel b) {
  return a.dist < b.dist;
}
 
ll minStops(Travel arr[], ll n, ll dist, ll petrol) {

  if(n <= 0) return -1;
  if(dist == 0) return 0;

  f(i, 0, n)
    arr[i].dist = dist - arr[i].dist;

  sort(arr, arr + n, cmp);
  ll res = 0;
  priority_queue<int, vi > pq;

  f(i, 0, n) {

    if(petrol >= dist)
      return res;
    else {
      while(!pq.empty() and petrol < arr[i].dist) {
        petrol += pq.top();
        pq.pop();
        res++;
      }

      if(petrol < arr[i].dist) 
        return -1;
      pq.push(arr[i].petrol);
    }
  }

  while(!pq.empty() and petrol < dist) {
    petrol += pq.top();
    pq.pop();
    res++;
  }

  if(petrol >= dist)
    return res;

  return -1;
}
 
int main() {
 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  ll t;
  cin >> t;
  for(ll i = 1; i <= t; i++) {
    ll n, petrol;
    cin>>n;
    Travel arr[n];

    f(j, 0, n)
      cin>>arr[j].dist>>arr[j].petrol;
      
    cin>>current>>petrol;

    cout<<minStops(arr, n, current, petrol)<<"\n";
  }
 
  return 0;
}
 