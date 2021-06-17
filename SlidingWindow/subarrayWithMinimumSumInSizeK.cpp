#include<iostream>
using namespace std;
 
int findSubarray(int arr[], int n, int k) {
  if(n <= 0 or k <= 0 or k > n) return INT_MAX;

  int ans = INT_MAX, i, curr = 0;

  for(i = 0; i<k; i++)
    curr += arr[i];

  ans = min(ans, curr);

  for(i = k; i<n; i++) {
    curr += arr[i] - arr[i - k];
    ans = min(ans, curr);
  }

  return ans;
}
 
int main() {
  
  int arr[] = {-2,10,1,3,2,-1,4,5};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout<<findSubarray(arr, n, 3)<<endl;
  
  return 0;
}
  