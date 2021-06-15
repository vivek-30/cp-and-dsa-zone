#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int> > pq;
 
int findSubsequence(int arr[], int n, int k) {
  if(n <= 0) return -1;

  for(int i=0; i<n; i++)
    pq.push(arr[i]);

  int ans = 0, sum = 0;
  while(not pq.empty()) {
    sum += pq.top();
    pq.pop();
    ans++;
    if(sum >= k) 
      return ans;
  }

  return -1;
}
 
int main() {
  
  int arr[] = {6,2,4,5,5,6,1,2,8};
  cout<<"Subsequence size is: "<<findSubsequence(arr, sizeof(arr)/sizeof(arr[0]), 20)<<endl;

  return 0;
}
  