#include<iostream>
#include<algorithm>
using namespace std;

void find_pair_equal_to_target(int arr[], int n, int target) {

  if(n <= 0)
    return;

  sort(arr, arr+n);

  int start = 0, end = n-1, current_sum;
  while(start <= end) {

    current_sum = arr[start] + arr[end];

    if(current_sum == target) {
      cout<<start<<" "<<end<<endl;
      return;
    }
    else if(current_sum > target)
      end--;
    else start++;
  }

  cout<<"No Pair Found\n";
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, target;
  cout<<"Enter array size\n";
  cin>>n;
  int arr[n];

  cout<<"Enter array elements\n";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  cout<<"Enter target\n";
  cin>>target;

  find_pair_equal_to_target(arr, n, target);

  return 0;
}
