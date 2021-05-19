#include<iostream>
using namespace std;

#define MAX 100

void find_element_method_2(int arr[MAX][MAX], int rows, int cols, int target) {
   
  if(rows == 0 and cols == 0) 
    return;

  int element, i = 0, j = cols - 1;

  while(i < rows and j >= 0) {

    element = arr[i][j];
    if(element == target) {
      cout<<"Element Found at position "<<i+1<<" "<<j+1<<endl;
      return;
    }
    else if(element > target)
      j--;
    else
      i++;
  }

  cout<<"Element doesn't Exists\n";
}

void find_element_method_1(int arr[MAX][MAX], int rows, int cols, int target) {

  if(rows == 0 and cols == 0) 
    return;

  int current_row, current_col, element, left = 0, right = cols-1, top = 0, bottom = rows-1;

  while(top <= bottom) {

    current_row = (top + bottom) / 2;

    while(left <= right) {

      current_col = (left + right) / 2;      
      element = arr[current_row][current_col];

      if(element == target) {
        cout<<"Element Found at position "<<current_row+1<<" "<<current_col+1<<endl;
        return;
      }
      else if(element > target) {
        right = current_col - 1;
      }
      else {
        left = current_col + 1;
      }
    }

    if(element > target) {
      bottom = current_row - 1;
    }
    else {
      top = current_row + 1;
    }

    left = 0;
    right = cols - 1;
  }

  cout<<"Element doesn't Exists\n";
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int rows, cols, target;
  cout<<"Enter rows and columns\n";
  cin>>rows>>cols;
  int arr[MAX][MAX];

  cout<<"Enter array elements\n";
  for(int i=0; i<rows; i++)
    for(int j=0; j<cols; j++)
      cin>>arr[i][j];

  cout<<"Enter data to be searched\n";
  cin>>target;

  find_element_method_1(arr, rows, cols, target);

  return 0;
}
