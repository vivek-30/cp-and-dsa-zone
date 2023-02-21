#include<iostream>
using namespace std;

#define N 9

void print(int board[N][N]) {
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++)
      cout<<board[i][j]<<" ";
    cout<<endl;
  }
}

void floodFill(int board[N][N], int row, int col, int oldColor, int newColor) {

  if(row < 0 or col < 0 or row >= N or col >= N or board[row][col] != oldColor)
    return;

  board[row][col] = newColor;

  floodFill(board, row + 1, col, oldColor, newColor);
  floodFill(board, row, col + 1, oldColor, newColor);
  floodFill(board, row - 1, col, oldColor, newColor);
  floodFill(board, row, col - 1, oldColor, newColor);
}


int main() {

  int board[N][N] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 0, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 6, 0, 0, 6},
    {0, 6, 0, 0, 8, 0, 2, 0, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};


  floodFill(board, 0, 2, 0, 1);
  print(board);

  return 0;
}
