#include<iostream>
using namespace std;

#define N 8

void printBoard(int board[N][N]) {

  cout<<"Queens positions are: "<<endl;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(board[i][j])
        cout<<"Q ";
      else cout<<"_ ";
    }
    cout<<endl;
  }
}

bool canPlace(int board[N][N], int row, int col) {

  if(row < 0 or col < 0 or row >= N or col >= N)
    return false;

  int i, j;

  // In Row.
  for(i=row; i>=0; i--)
    if(board[i][col])
      return false;

  // In Upper Left Diagonal.
  for(i=row, j=col; i>=0 && j>=0; i--, j--)
    if(board[i][j])
      return false;

  // In Upper Right Diagonal.
  for(i=row, j=col; i>=0 && j<N; i--, j++)
    if(board[i][j])
      return false;

  return true;
}

bool placeQueens(int board[N][N], int row) {

  if(row > N)
    return false;

  if(row == N) {
    printBoard(board);
    return false;
  }

  for(int col=0; col<N; col++) {
    if(canPlace(board, row, col)) {
      
      board[row][col] = 1;
      if(placeQueens(board, row + 1))
        return true;

      board[row][col] = 0;
    }
  }

  return false;
}

int main() {

  int board[N][N];

  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      board[i][j] = 0;

  placeQueens(board, 0);

  return 0;
}
