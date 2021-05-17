#include<iostream>
using namespace std;

void find_subarray_equal_to_x(int arr[], int n, int target) {

  if(n <= 0)
    return;

  int start = 0, end = 0, result = arr[0];

  while(start < n and end < n) {
    if(result == target)
      break;

    if(result < target) {
      end++;
      result += arr[end];
    }
    else {
      result -= arr[start];
      start++;
    }
  }

  if(start == n or end == n) {
    cout<<"Target sum isn't pressent in the array\n";
    return;
  }
  else {
    cout<<start<<" "<<end<<endl;
  }

}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, t = 1, curr = 1, target;

  cout<<"Enter total test cases\n";
  cin>>t;

  while(t--) {

    cout<<"Enter array size\n";
    cin>>n;
    int arr[n];

    cout<<"Enter array elements\n";
    for(int i=0; i<n; i++)
      cin>>arr[i];

    cout<<"Enter target sum\n";
    cin>>target;

    find_subarray_equal_to_x(arr, n, target);
  }
  return 0;
}
