#include<iostream>
using namespace std;

void waveSort(int arr[], int n) {

  if(n <= 0)
    return;

  for(int i = 1; i < n - 1; i += 2) {
    if(arr[i] > arr[i - 1])
      swap(arr[i], arr[i - 1]);
    if(arr[i] > arr[i + 1])
      swap(arr[i], arr[i + 1]);
  }
}

int main() {

  int n;
  cout<<"Enter array size\n";
  cin>>n;
  int arr[n];

  cout<<"Enter array elements\n";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  waveSort(arr, n);
  cout<<"Sorted Array Is: \n";

  for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
  cout<<endl;

  return 0;
}
