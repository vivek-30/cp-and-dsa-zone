#include<iostream>
using namespace std;

void print_subarrays_sum(int arr[], int n) {
  if(n<=0)
    return;

  int sum = 0;

  int pre_sum[n];
  pre_sum[0] = arr[0];
  
  for(int i=1; i<n; i++)
    pre_sum[i] = pre_sum[i-1] + arr[i];

  for(int i=0; i<n; i++) {
    for(int j=i; j<n; j++) {

      if(i > 0)
        sum = pre_sum[j] - pre_sum[i-1];
      else sum = pre_sum[j];

      cout<<sum<<" ";
    }
  }
  cout<<endl;
}

int main() {

  int n;
  cout<<"Enter array Size\n";
  cin>>n;
  int arr[n];

  cout<<"Enter array Elements\n";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  print_subarrays_sum(arr, n);

  return 0;
}
