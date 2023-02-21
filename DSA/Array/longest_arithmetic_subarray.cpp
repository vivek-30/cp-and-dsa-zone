#include<iostream>
using namespace std;

int find_longest_arithmetic_subarray(int arr[], int n) {

  if(n<=1)
    return -1;

  int curr_length = 2, prev_diff = arr[0] - arr[1], curr_diff, max_length = 2;

  for(int i=2; i<n; i++) {
    curr_diff = arr[i-1] - arr[i];
    if(curr_diff == prev_diff)
      curr_length++;
    else {
      prev_diff = curr_diff;
      curr_length = 2;
    }

    if(curr_length > max_length)
      max_length = curr_length;
  }

  return max_length;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, t = 1, curr = 1;

  cin>>t;
  while(t--) {
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
      cin>>arr[i];

    int len = find_longest_arithmetic_subarray(arr, n);
    cout<<"#"<<curr++<<": "<<len<<endl;
  }
  return 0;
}
