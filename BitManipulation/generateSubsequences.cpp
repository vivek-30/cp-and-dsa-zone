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

void print(int mask, int arr[]) {
  
  int pos = 0;

  if(mask == 0)
    cout<<" ";
  else {
    while(mask) {
      if(mask&1){
        cout<<arr[pos];
      }
      pos++;
      mask = mask>>1;
    }
  }
  cout<<endl;
}

void generate(int arr[], int n) {
  f(i, 0, ((1<<n)-1)) {
    print(i, arr);
  }
}

int main() {

  int arr[] = {1,2,3,4};
  generate(arr, sizeof(arr)/sizeof(arr[0]));

  return 0;
}
