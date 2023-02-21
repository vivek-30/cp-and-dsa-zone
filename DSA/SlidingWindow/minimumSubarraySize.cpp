#include <iostream>
using namespace std;

// O(N)
int findSubarraySize(int arr[], int n, int x)
{
  int curr = 0, ans = INT_MAX, start = 0, end = 0;
  while (end < n)
  {

    if (arr[end] > x)
      return 1;

    while (curr <= x and end < n)
      curr += arr[end++];

    while (curr > x and start < end)
    {
      ans = min(ans, end - start);
      curr -= arr[start++];
    }
  }

  return ans;
}
