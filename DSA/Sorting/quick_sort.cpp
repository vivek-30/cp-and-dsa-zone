#include<iostream>
#include<time.h>
using namespace std;

int makePartition(int arr[], int start, int end) {

  int piviot = arr[end], piviotIndex = start;
  
  for(int i = start; i < end; i++) {
    if(arr[i] <= piviot) {
      swap(arr[i], arr[piviotIndex]);
      piviotIndex++;
    }
  }
  swap(arr[piviotIndex], arr[end]);

  return piviotIndex;
}

int randomPartition(int arr[], int start, int end) {
  
  srand(time(NULL));
  int randomNum = start + rand() % (end - start);
  swap(arr[start], arr[randomNum]);

  return makePartition(arr, start, end);
}

void quickSort(int arr[], int start, int end) {

  if(start >= end)
    return;
  
  int piviotIndex = randomPartition(arr, start, end);
  quickSort(arr, start, piviotIndex - 1);
  quickSort(arr, piviotIndex + 1, end);
}

int main() {

  int n;
  cout<<"Enter array size\n";
  cin>>n;
  int arr[n];

  cout<<"Enter array elements\n";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  quickSort(arr, 0, n - 1);
  cout<<"Sorted Array Is: \n";

  for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
  cout<<endl;

  return 0;
}
