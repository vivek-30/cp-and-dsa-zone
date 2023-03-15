class Solution {
public:
  void nextPermutation(vector<int>& arr) {
    int n = arr.size();
    int i = n-2;
    while(i >= 0) {
      if(arr[i] < arr[i+1]) {
        break;
      }
      i--;
    }

    if(i < 0) {
      reverse(arr.begin(), arr.end());
    } else {
      int j = i+1;
      for(j = n-1; j>i; j--) {
        if(arr[j] > arr[i]) break;
      }

      swap(arr[i], arr[j]);
      reverse(arr.begin()+i+1, arr.end());
    }
  }
};
