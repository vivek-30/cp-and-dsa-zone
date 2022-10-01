#include <bits/stdc++.h>
using namespace std;


// Solution 1 => Top Down
class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    return solve(0, n - 1, nums, dp);
  }

  int solve(int i, int n, vector<int> &arr, vector<int> &dp)
  {

    if (i > n)
      return INT_MAX;

    if (i == n)
      return 0;

    if (dp[i] != INT_MAX)
      return dp[i];

    int ans = INT_MAX;
    for (int j = 1; j <= arr[i]; j++)
    {
      int curr = solve(i + j, n, arr, dp);
      if (curr != INT_MAX)
        curr = curr + 1;
      ans = min(ans, curr);
    }

    return dp[i] = ans;
  }
};

// Solution 2 => Bottom Up (Exactly Similar To LIS)
int solve2(vector<int> &arr) {
  
  int n = arr.size();
  vector<int> dp(n, INT_MAX);
  dp[0] = 0;

  for(int i=1; i<n; i++) {
    for(int j=0; j<i; j++) {
      if(j + arr[j] >= i) {   // if we are able to jump to end (i.e ith pos.) while standing at jth pos.
        dp[i] = min(dp[i], dp[j] + 1);
      }
    }
  }

  return dp[n-1];
}

// Solution 3 => Greedy
int solve3(vector<int> &arr) {
  
  int res = 0, i = 0, j = 0, n = arr.size(), far = 0, jump = 0;
  while(i < n) {
    if(far == 0) {
      far = (jump == 0) ? arr[i] : jump;
      res++;
    }
    else {
      far--;
      jump = max(jump, arr[i]);
    }
    i++;
  }

  return res;
}

int main() {
  vector<int> v = {2, 1, 1, 2, 1, 3, 2, 0, 5};
  cout<<solve3(v)<<endl;
}
