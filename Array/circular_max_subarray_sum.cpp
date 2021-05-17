#include<iostream>
using namespace std;

int give_sum_with_kadens_algo(int arr[], int n) {

  int current_sum = 0, max_sum = INT_MIN;

  for(int i=0; i<n; i++) {

    current_sum += arr[i];

    if(current_sum > max_sum)
      max_sum = current_sum;

    if(current_sum < 0)
      current_sum = 0;
  }
  return max_sum;
}

int give_max_circular_subarray_sum(int arr[], int n) {

  if(n <= 0)
    return INT_MIN;

  // Case 1. No Wrapping.
  int no_wrap_sum, wrap_sum, array_sum = 0;
  no_wrap_sum = give_sum_with_kadens_algo(arr, n);

  // Case 2. Wrapping.
  for(int i=0; i<n; i++) {
    array_sum += arr[i];
    arr[i] = -arr[i];
  }

  wrap_sum = -(give_sum_with_kadens_algo(arr, n));
  wrap_sum = array_sum - wrap_sum;

  return max(wrap_sum, no_wrap_sum);
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cout<<"Enter array size\n";
  cin>>n;
  int arr[n];

  cout<<"Enter array elements\n";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  int max = give_max_circular_subarray_sum(arr, n);
  cout<<"Max sum is : "<<max<<endl;

  return 0;
}
