#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
bool myComparator(pair<int, int> &a, pair<int, int> &b) {
  return a.second < b.second;
}
 
int main() {
  
  int n, item;
  cout<<"Enter array size"<<endl;
  cin>>n;

  int result[n], arr[n];

  vector<pair<int, int> > v;
  cout<<"Enter array elements\n";
  for(int i = 0; i < n; i++) {
    cin>>item;
    v.push_back(make_pair(i, item));
  }

  sort(v.begin(), v.end(), myComparator);

  for(int i = 0; i < n; i++)
    result[v[i].first] = i;

  for(int i = 0; i < n; i++)
    cout<<result[i]<<" ";
  cout<<endl;
  
  return 0;
}
  