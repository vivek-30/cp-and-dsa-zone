#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
  int s = 0, e = nums.size() - 1, mid, n = nums.size();
  if (n == 1)
    return 0;
  while (s <= e)
  {
    mid = (s + e) / 2;

    if (mid > 0 and mid < n - 1)
    {
      if (nums[mid] > nums[mid + 1] and nums[mid] > nums[mid - 1])
        return mid;
      else if (nums[mid] < nums[mid - 1])
        e = mid - 1;
      else
        s = mid + 1;
    }
    else if (mid == 0)
    {
      if (nums[mid] > nums[mid + 1])
        return mid;
      else
        s = mid + 1;
    }
    else if (nums[mid] > nums[mid - 1])
      return mid;
    else
      e = mid - 1;
  }

  return -1;
}
