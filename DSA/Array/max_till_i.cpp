#include<iostream>
using namespace std;

void collect_max(int arr[], int store_max[], int n) {

  if(n == 0)
    return;

  int max = INT_MIN, i;

  for(int i=0; i<n; i++) {
    if(arr[i] > max)
      max = arr[i];
    store_max[i] = max;
  }
}

int give_max(int arr[], int n, int start, int end) {

  int max = INT_MIN;

  if(start < 0 || end < 0 || start > end || start > n || end > n)
    return max;

  for(int i=start; i<end; i++)
    if(arr[i] > max)
      max = arr[i];

  return max;
}

int main() {

  int n, t, start, end, max;
  cout<<"Enter array Size\n";
  cin>>n;
  int arr[n];
  cout<<"Enter array Elements\n";

  for(int i=0; i<n; i++)
    cin>>arr[i];

  int store_max[n];
  collect_max(arr, store_max, n);

  cout<<"Max array is : ";
  for(int i=0; i<n; i++)
    cout<<store_max[i]<<" ";
  cout<<endl;

  cout<<"Enter Total Test Cases\n";
  cin>>t;

  while(t--) {
    cout<<"Enter starting and ending point\n";
    cin>>start>>end;

    max = give_max(store_max, n, start-1, end);
    cout<<"Max in Range "<<start<<" and "<<end<<" is "<<max<<endl;
  }

  return 0;
}
