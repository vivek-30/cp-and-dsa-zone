#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
  // TC - O(N*LogN), SC - O(1);
  vvi merge(vvi& arr) {
    vvi ans;

    sort(begin(arr), end(arr), [](vi x, vi y) {
      if(x[0] == y[0]) return x[1] < y[1];
      return x[0] < y[0];
    });

    int i = 0, n = arr.size();
    while(i < n) {
      pair<int, int> curr = {arr[i][0], arr[i][1]};
      while(++i < n && arr[i][0] >= curr.first and arr[i][0] <= curr.second) {
        curr.second = max(curr.second, arr[i][1]);
      }
      ans.push_back({curr.first, curr.second});
    }

    return ans;
  }
};