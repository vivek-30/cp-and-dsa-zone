#include<iostream>
using namespace std;

// Simple and Efficeient Approach is to replace a number with 1 if it is perfect number else 0 in original array and then simply find subarray of size k having maximum one's (i.e., having maximum sum).

bool isPerfect(int num) {
  int sum = 1;
  for(int i=2; i*i<=num; i++) { // Note => always start the loop with 2 as ( num / 1 ==  num ) which voilates perfect number property.
    if(num % i == 0) {
      sum += i;
      if(i != num/i)
        sum += num/i;
    }
  }

  return sum == num and num != 1;
}
 
int findSubarraySize(int arr[], int n, int k) {
  if(k<0 or n<0 or k>n) return -1;

  int i = 0, ans = 0, curr = 0;

  for(; i<k; i++) 
    if(isPerfect(arr[i]))
      ans++;

  curr = ans;
  for(; i<n; i++) {
    if(isPerfect(arr[i]))
      curr++;

    if(isPerfect(arr[i-k])) 
      curr--;

    ans = max(ans, curr);
  }
  
  return ans;
}
 
int main() {
  
  int arr[] = {28,2,3,6,496,99,8128,24};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout<<findSubarraySize(arr, n, 4)<<endl;
  
  return 0;
}
  