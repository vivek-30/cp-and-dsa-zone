#include<iostream>
using namespace std;

#define MAX 100

void print_spiral_order(int arr[MAX][MAX], int rows, int cols) {

  if(rows == 0 and cols == 0) 
    return;

  int top = 0, bottom = rows-1, left = 0, right = cols-1, direction = 0;

  while(top <= bottom and left <= right) {

    if(direction == 0) {
      for(int i=left; i<=right; i++)
        cout<<arr[top][i]<<" ";
      top++;
    }
    else if(direction == 1) {
      for(int i=top; i<=bottom; i++)
        cout<<arr[i][right]<<" ";
      right--;
    }
    else if(direction == 2) {
      for(int i=right; i>=left; i--)
        cout<<arr[bottom][i]<<" ";
      bottom--;
    }
    else {
      for(int i=bottom; i>=top; i--)
        cout<<arr[i][left]<<" ";
      left++;
    }

    direction = (direction + 1) % 4;
  }
  cout<<"\n";
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int rows,cols;
  cout<<"Enter rows and columns\n";
  cin>>rows>>cols;
  int arr[MAX][MAX];

  cout<<"Enter array elements\n";
  for(int i=0; i<rows; i++)
    for(int j=0; j<cols; j++)
      cin>>arr[i][j];

  print_spiral_order(arr, rows, cols);

  return 0;
}
