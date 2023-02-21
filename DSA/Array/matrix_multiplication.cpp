#include<iostream>
using namespace std;

#define MAX 100

void multiply_matrix(int first[MAX][MAX], int second[MAX][MAX], int rows1, int cols1, int rows2, int cols2) {

  if((rows1 == 0 and cols1 == 0) || (rows2 == 0 and cols2 == 0) || rows1 != cols2) 
    return;

  int result[rows1][cols2];
  for(int i=0; i<rows1; i++)
    for(int j=0; j<cols2; j++)
      result[i][j] = 0;

  for(int i=0; i<rows1; i++) {
    for(int j=0; j<cols2; j++) {
      for(int k=0; k<cols1; k++) {
        result[i][j] += (first[i][k] * second[k][j]);
      }
    }
  }
  
  cout<<"Multiplied Matrix is :\n";
  for(int i=0; i<rows1; i++) {
    for(int j=0; j<cols2; j++)
      cout<<result[i][j]<<" ";
    cout<<endl;
  }
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int rows1, cols1, rows2, cols2;
  int first[MAX][MAX], second[MAX][MAX];
  cout<<"Enter rows and columns of matrix 1\n";
  cin>>rows1>>cols1;

  cout<<"Enter matrix 1 elements\n";
  for(int i=0; i<rows1; i++)
    for(int j=0; j<cols1; j++)
      cin>>first[i][j];

  cout<<"Enter rows and columns of matrix 2\n";
  cin>>rows2>>cols2;

  cout<<"Enter matrix 2 elements\n";
  for(int i=0; i<rows2; i++)
    for(int j=0; j<cols2; j++)
      cin>>second[i][j];

  multiply_matrix(first, second, rows1, cols1, rows2, cols2);

  return 0;
}
