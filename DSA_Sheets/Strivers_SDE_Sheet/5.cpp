class Solution {
public:
    void sortColors(vector<int>& arr) {

      int n = arr.size();

      // Approach 1: TC - O(N*Log(N)), SC - O(1);
      // sort(begin(arr), end(arr)); 

      // Approach 2: TC - O(N), SC - O(1), Two Pass Algorithm.
      // int zero_count = 0, one_count = 0, two_count = 0;
      // for(int &val: arr) {
      //   if(val == 0) zero_count++;
      //   else if(val == 1) one_count++;
      //   else two_count++;
      // }
      // int i = 0;
      // while(zero_count-->0) arr[i++] = 0;
      // while(one_count-->0) arr[i++] = 1;
      // while(two_count-->0) arr[i++] = 2;

    // Approach 3: TC - O(N), SC - O(1), Single Pass Algorithm.
    int low = 0, mid = 0, high = n-1;
    while(mid <= high) {
      if(arr[mid] == 0) {
        swap(arr[low], arr[mid]);
        low++, mid++;
      } else if(arr[mid] == 1) {
        mid++;
      } else {
        swap(arr[mid], arr[high]);
        high--;
      }
    }
  }
};