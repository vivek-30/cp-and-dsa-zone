#include <iostream>
using namespace std;

#define mid(l, r) (l + (r - l) / 2)

int findKRotation(int arr[], int n)
{
  if (n <= 0)
    return 0;

  int start = 0, end = n - 1, mid, next, prev;

  if (arr[start] <= arr[end])
    return 0;

  while (start <= end)
  {
    mid = mid(start, end);
    next = (mid + 1) % n;
    prev = (mid + n - 1) % n;
    if (arr[mid] < arr[next] and arr[mid] < arr[prev])
      return mid;
    else if (arr[mid] < arr[end])
      end = mid - 1;
    else
      start = mid + 1;
  }

  return 0;
}
