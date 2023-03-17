class Solution {
public:
    // Approach 1: TC - O(N), SC - O(N)
    int maxProfit2(vector<int>& arr) {
      int ans = 0, n = arr.size();

      vector<int> prefix(n, 1e9);

      for(int i=0; i<=n-1; i++) {
        prefix[i] = min(prefix[i], arr[i]);
        if(i > 0) {
          prefix[i] = min(prefix[i], prefix[i-1]);
        }
      }

      for(int i=n-1; i>=1; i--) {
        ans = max(ans, arr[i] - prefix[i-1]);
      }

      return ans;
    }

    // Approach 2: TC - O(N), SC - O(1)
    int maxProfit(vector<int>& arr) {
      int n = arr.size();
      int cheapestStockPrice = 1e9, bestStockPrice = 0;

      for(int i=0; i<n; i++) {
        cheapestStockPrice = min(cheapestStockPrice, arr[i]);
        bestStockPrice = max(bestStockPrice, arr[i] - cheapestStockPrice);
      }

      return bestStockPrice;
    }
};