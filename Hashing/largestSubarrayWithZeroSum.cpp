#include <bits/stdc++.h>
using namespace std;

int findSubarrayLength(int arr[], int n)
{
  if (n <= 0)
    return 0;

  int ans = INT_MIN;
  unordered_map<int, int> m;
  long long int sum = 0;

  for (int i = 0; i < n; i++)
  {

    sum += arr[i];

    if (arr[i] == 0 and ans == INT_MIN)
      ans = 1;
    else if (sum == 0)
      ans = i + 1;
    else if (m.find(sum) != m.end())
      ans = max(ans, i - m[sum]);
    else
      m.insert({sum, i}); // Note -> (very very important) insert sum only when it is not present already.
  }

  return ans != INT_MIN ? ans : 0;
}

int main()
{

  int arr[] = {1, 2, -2, 3, 4, 1, -8, 0, 4, 9};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << findSubarrayLength(arr, n) << endl;

  return 0;
}
