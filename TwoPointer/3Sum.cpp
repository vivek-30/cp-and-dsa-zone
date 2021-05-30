#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > threeSum(vector<int> &nums, int target)
{

  int n = nums.size();
  int start, end;

  vector<vector<int> > ans;

  if (n <= 2)
    return ans;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < n; i++)
  {

    if (i > 0 and nums[i] == nums[i - 1])
      continue;

    start = i + 1;
    end = n - 1;

    while (start < end)
    {
      if (nums[i] + nums[start] + nums[end] == target)
      {
        ans.push_back({nums[i], nums[start], nums[end]}); // Works only with c++17 standards.

        while (start < end and nums[start] == nums[start + 1])
          start++;
        while (start < end and nums[end] == nums[end - 1])
          end--;

        start++;
        end--;
      }
      else if (nums[i] + nums[start] + nums[end] < target)
        start++;
      else
        end--;
    }
  }

  return ans;
}

int main()
{

  vector<int> nums{2, 5, 4, -1, 0, 4, 2, 1, 7, -3};

  vector<vector<int> > result = threeSum(nums, 4);

  cout<<"Required Triplets are: ";
  for (auto row : result)
  {
    cout<<"[";
    for (auto num : row)
      cout << setw(2) << num << ",";
    cout << "], ";
  }

  cout<<endl;

  return 0;
}
