#include <bits/stdc++.h>
using namespace std;

#define N 9

vector<pair<int, int> > places;

void print(int board[N][N])
{

  cout << "Solution Is:\n";
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cout << board[i][j] << " ";
    cout << "\n";
  }
}

void findEmptyBox(int board[N][N])
{
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (board[i][j] == 0)
        places.push_back(make_pair(i, j));
}

bool canPlace(int board[N][N], int row, int col, int num)
{
  if (row < 0 or col < 0 or row >= N or col >= N)
    return false;

  for (int i = 0; i < N; i++)
    if (board[i][col] == num)
      return false;

  for (int i = 0; i < N; i++)
    if (board[row][i] == num)
      return false;

  int box_size = sqrt(N);
  int box_row = row - row % box_size;
  int box_col = col - col % box_size;

  for (int i = box_row; i < box_row + box_size; i++)
    for (int j = box_col; j < box_col + box_size; j++)
      if (board[i][j] == num)
        return false;

  return true;
}

bool solveSudoku(int board[N][N], int curr)
{

  if (places.empty() or curr >= places.size())
    return true;

  int row, col;

  for (int num = 1; num <= N; num++)
  {

    row = places[curr].first;
    col = places[curr].second;

    if (canPlace(board, row, col, num))
    {
      board[row][col] = num;

      if (solveSudoku(board, curr + 1))
        return true;

      board[row][col] = 0;
    }
  }

  return false;
}

int main()
{

  int board[N][N] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                     {6, 0, 0, 1, 9, 5, 0, 0, 0},
                     {0, 9, 8, 0, 0, 0, 0, 6, 0},
                     {8, 0, 0, 0, 6, 0, 0, 0, 3},
                     {4, 0, 0, 8, 0, 3, 0, 0, 1},
                     {7, 0, 0, 0, 2, 0, 0, 0, 6},
                     {0, 6, 0, 0, 0, 0, 2, 8, 0},
                     {0, 0, 0, 4, 1, 9, 0, 0, 5},
                     {0, 0, 0, 0, 8, 0, 0, 7, 9}};

  findEmptyBox(board);
  if (solveSudoku(board, 0))
    print(board);
  else
    cout << "No Possible Solution\n";

  return 0;
}
