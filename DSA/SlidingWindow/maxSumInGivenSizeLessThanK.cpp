#include<iostream>
using namespace std;
 
// O(N * K)
int maxSubarray1(int arr[], int n, int k, int x) {
  int curr = 0, maxsum = INT_MIN;
  for(int i=0; i<=n-k; i++) {
    for(int j=i; j<i+k; j++) {
      curr+=arr[j];
    }
    if(curr < x)
      maxsum = max(maxsum, curr);
    curr = 0;
  }
  return maxsum;
}

// O(N)
int maxSubarray2(int arr[], int n, int k, int x) {
  int curr = 0, maxsum = INT_MIN;

  if(k<0  or k>n) return INT_MIN;

  if(k==0 or k == n) {
    for(int i=0; i<n; i++)
      if(arr[i] < x)
        maxsum = max(maxsum, arr[i]);
    return maxsum;
  }

  for(int i=0; i<k; i++)
    curr+=arr[i];

  maxsum = curr < x ? curr : INT_MIN;

  for(int i=k; i<n; i++) {

    curr -= arr[i-k];
    curr += arr[i];
    
    if(curr < x)
      maxsum = max(maxsum, curr);
    
  }
  return maxsum;
}
 
int main() {
  
  int arr[] = {7,5,4,6,8,9};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<maxSubarray2(arr, n, 3, 20)<<endl;
  
  return 0;
}
  