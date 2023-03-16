class Solution {
public:

    // Kadane's Algorithms TC - O(N), SC - O(1);
    int maxSubArray(vector<int>& arr) {
      int ans = -1e9, curr = 0;
      for(int i = 0; i<arr.size(); i++) {
        curr += arr[i];
        ans = max(ans, curr);

        if(curr < 0) curr = 0;
      }

      return ans;
    }

    int getMaxResult(int s, int e, vector<int>& arr) {
      if(s > e) return -1e9;

      int m = (s + e) >> 1;

      int left_max = getMaxResult(s, m-1, arr);
      int right_max = getMaxResult(m+1, e, arr);

      int curr_left = 0, curr_right = 0, curr_val = 0;
      for(int i = m-1; i >= s; i--) {
        curr_val += arr[i];
        curr_left = max(curr_left, curr_val);
      }

      curr_val = 0;
      for(int i = m+1; i <= e; i++) {
        curr_val += arr[i];
        curr_right = max(curr_right, curr_val);
      }

      return max({right_max, left_max, (curr_left + curr_right + arr[m])});
    }

    // Divide & Conquer TC - O(N*Log(N)), SC - O(N);
    int maxSubArray2(vector<int>& arr) {
      return getMaxResult(0, arr.size()-1, arr);
    }
};