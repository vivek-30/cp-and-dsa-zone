#include<iostream>
using namespace std;

#define MAX 100

void give_transpose(int arr[MAX][MAX], int N, int ** result) {

  if(N <= 0) 
    return;

  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      result[i][j] = arr[j][i];
}

void efficient_transpose(int arr[MAX][MAX], int N) {

  if(N <= 0) 
    return;

  int temp;

  for(int i=0; i<N; i++) {
    for(int j=i; j<N; j++) { // As we have to switch either upper or lower triangle along diagonal.
      temp = arr[i][j];
      arr[i][j] = arr[j][i];
      arr[j][i] = temp;
    }
  }
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cout<<"Enter Matrix Order\n";
  cin>>N;
  int arr[MAX][MAX];

  cout<<"Enter array elements\n";
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      cin>>arr[i][j];

  // int** result = new int* [N];
  // for(int i=0; i<N; i++) {
  //   result[i] = new int[N];
  // }

  // give_transpose(arr, N, result);
  efficient_transpose(arr, N);

  cout<<"Transpose :\n";
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++)
      cout<<arr[i][j]<<" ";
    cout<<endl;
  }

  return 0;
}
