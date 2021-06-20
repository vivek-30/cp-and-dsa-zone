#include <bits/stdc++.h>
using namespace std;

int findMinCost(int arr[], int n) {

  if(n <= 0) return -1;
  if(n == 1) return arr[0];

  priority_queue<int, vector<int>, greater<int> > pq;
  int ans = 0, num1, num2;

  for(int i=0; i<n; i++)
    pq.push(arr[i]);

  while(pq.size() > 1) {
    num1 = pq.top();
    pq.pop();
    num2 = pq.top();
    pq.pop();
    ans  += num1 + num2;
    pq.push(num1 + num2);
  }

  return ans;
}

int main()
{

  int arr[] = {2, 3, 4};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout<<findMinCost(arr, n)<<endl;
  return 0;
}
