#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<=0)
          return 0;
      if(n == 1)
        return (k >= 1 or nums[0] ? 1 : 0);
      
      int i = 0, j = 0, ans = 0, zeroCount = 0;
      
      while(j < n){
      
        if(nums[j] == 0)
          zeroCount++;
        
        while(zeroCount > k and i <= j) {
          if(nums[i] == 0)
            zeroCount--;
          i++;
        }
        ans = max(ans, j - i + 1);
        j++;
      }
      
      return ans;
    }
};