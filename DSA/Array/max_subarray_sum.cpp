#include<iostream>
using namespace std;

int give_max_subarray_sum(int arr[], int n) {

  if(n <= 0)
    return INT_MIN;

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

  int max = give_max_subarray_sum(arr, n);
  cout<<"Max sum is : "<<max<<endl;

  return 0;
}
