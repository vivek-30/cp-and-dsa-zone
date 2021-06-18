#include <bits/stdc++.h>
using namespace std;

// O(N) + space O(N)
int findSubarray1(int arr[], int n) {

  if(n <= 0) return 0;
  unordered_map<int, int> m;

  int ans = 0, sum = 0;
  m[0] = 1;

  for(int i=0; i<n; i++) {
    sum += arr[i];

    if(m.find(sum) != m.end()) {
      ans += m[sum];
      m[sum] = ans;
    }
    else m[sum] = 1;
   }

  return ans;
}

// O(N * N)
int findSubarray2(int arr[], int n) {
  if(n<=0) return 0;
  int ans = 0, sum = 0;

  for(int i=0; i<n; i++) {
    for(int j=i; j<n; j++) {
      sum += arr[j];

      if(sum == 0 or arr[j] == 0)
        ans++;
    }
    sum = 0;
  }

  return ans;
}

int main()
{

  int arr[] = {6, 3, -1, -3, 4, -2, 2,4, 6, -12, -7};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << findSubarray2(arr, n) << endl;

  return 0;
}
