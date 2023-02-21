#include<iostream>
using namespace std;

bool check_sorted(int arr[], int n) {
  if(n == 1)
    return true;

  bool isSorted = check_sorted(arr+1, n-1);
  return (isSorted && arr[0] < arr[1]);
}

int main() {
  int n;
  cout<<"Enter array size\n";
  cin>>n;
  int arr[n];
  cout<<"Enter array elements\n";
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }

  if(check_sorted(arr, n))
    cout<<"Sorted\n";
  else cout<<"Not Sorted\n";
  return 0;
}