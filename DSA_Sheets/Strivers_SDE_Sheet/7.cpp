class Solution {
public:

    void reverseMatrixRows(int* res[], int n) {
      for(int i=0; i<n; i++) {
        reverse(res[i], res[i]+n);
      }
    }

    // Approach 1: TC - O(N^2), SC - O(N^2);
    void rotate2(vector<vector<int>>& arr) {
      int n = arr.size();

      int* res[n];
      for(int i=0; i<n; i++) res[i] = new int[n];

      for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
          res[j][i] = arr[i][j];
        }
      }

      reverseMatrixRows(res, n);

      for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
          arr[i][j] = res[i][j];
        }
      }

      for(int i=0; i<n; i++) delete[] res[i];
    }

    // Approach 2: TC - O(N^2), SC - O(1);
    void rotate(vector<vector<int>>& arr) {
      int n = arr.size();

      for(int i = 0; i<n; i++) {
        for(int j = i; j<n; j++) {
          swap(arr[i][j], arr[j][i]);
        }
      }

      for(int i = 0; i<n; i++) {
        reverse(arr[i].begin(), arr[i].end());
      }
    }
};