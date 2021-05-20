#include<iostream>
#include<math.h>
using namespace std;
#define N 9

void printSudoku(int board[N][N]) {
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++)
      cout<<board[i][j]<<" ";
    cout<<endl;
  }
}

bool isEmptyCell(int board[N][N], int& row, int& col) {
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(board[i][j] == 0) {
        row = i;
        col = j;
        return true;
      }
    }
  }
  return false;
}

bool canPlace(int board[N][N], int row, int col, int num) {
  
  if(row >=N or col >= N)
    return false;

  // In Column.
  for(int i=0; i<N; i++)
    if(board[row][i] == num)
      return false;
  
  // In Row.
  for(int i=0; i<N; i++)
    if(board[i][col] == num)
      return false;

  // In Box.
  int n = sqrt(N);
  int startingRow = row - row % n;
  int startingCol = col - col % n;

  for(int i = startingRow; i < (startingRow + n); i++)
    for(int j = startingCol; j < (startingCol + n); j++)
      if(board[i][j] == num)
        return false;
    
  return true;
}

bool solveSudoku(int board[N][N]) {

  int row = -1, col = -1;
  if(!isEmptyCell(board, row, col)) 
    return true;

  for(int num=1; num<=N; num++) {
    if(canPlace(board, row, col, num)) {
      board[row][col] = num;
      if(solveSudoku(board))
        return true;
      board[row][col] = 0;
    }
  }

  return false;
}

int main() {

  int board[N][N] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};

  if(solveSudoku(board))
    printSudoku(board);
  else cout<<"No Possible Solution\n";

  return 0;
}
