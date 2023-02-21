#include <bits/stdc++.h>
using namespace std;

#define mid(l, r) (l + (r - l) / 2)

int findElement(vector<int> &arr, int val)
{
  int start = 0, end = arr.size() - 1, mid;

  while (start <= end)
  {

    mid = mid(start, end);

    if (arr[mid] == val)
      return mid;
    else if (arr[mid] < arr[end])
    {
      if (val > arr[mid] and val <= arr[end])
        start = mid + 1;
      else
        end = mid - 1;
    }
    else
    {
      if (val < arr[mid] and val >= arr[start] )
        end = mid - 1;
      else
        start = mid + 1;
    }
  }

  return -1;
}

int main()
{
  vector<int> v{7, 8, 10, 2, 4, 5, 6};
  cout << findElement(v, 7) << endl;
  cout << findElement(v, 8) << endl;
  cout << findElement(v, 6) << endl;

  return 0;
}
