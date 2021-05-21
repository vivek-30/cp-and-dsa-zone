#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {

  if(n <= 0)
    return;

  bool isSwaped = false;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n - i - 1; j++) {
      if(arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        isSwaped = true;
      }
    }

    if(!isSwaped)
      break;

    isSwaped = false;
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

  bubbleSort(arr, n);
  cout<<"Sorted Array Is: \n";

  for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
  cout<<endl;

  return 0;
}
