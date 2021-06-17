#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Time - O(N * LogN) LogN for insertion in map and N for total nodes in tree.
void printUtil(int arr[], map<int, vector<int> > &m, int curr, int dist, int n) {
  
  if(curr >= n or n <= 0) return;

  int left = (2 * curr) + 1, right = (2 * curr) + 2;

  m[dist].push_back(arr[curr]);

  printUtil(arr, m, left, dist - 1, n); // Go To Left Child.
  printUtil(arr, m, right, dist + 1, n); // Go To Right Child.
}
 
void printVerticalOrder(int arr[], int n) {

  map<int, vector<int> > m;
  printUtil(arr, m, 0, 0, n);

  cout<<"Vertical Order is:\n";
  for(auto i: m) {
    for(int j=0; j<(i.second).size(); j++) 
      cout<<i.second[j]<<" ";
    cout<<endl;
  }
}
 
int main() {
  
  int arr[] = {10, 7, 4, 3, 11, 14, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  printVerticalOrder(arr, n);
  
  return 0;
}
  