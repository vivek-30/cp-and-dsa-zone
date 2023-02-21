#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {

  if(n <= 0)
    return;

  int pos, minValue;

  for(int i = 0; i < n; i++) {

    minValue = arr[i];
    pos = i;

    for(int j = i + 1; j < n; j++) {
      if(arr[j] < minValue) {
        pos = j;
        minValue = arr[j];
      }
    }

    swap(arr[i], arr[pos]);
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

  selectionSort(arr, n);
  cout<<"Sorted Array Is: \n";

  for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
  cout<<endl;

  return 0;
}
