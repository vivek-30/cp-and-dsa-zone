#include<iostream>
using namespace std;

#define N 5

void printMaze(int path[N][N]) {

  cout<<"Maze Path is: "<<endl;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cout<<path[i][j]<<" ";
    }
    cout<<endl;
  }
}

bool solveMaze(int maze[N][N], int path[N][N], int row, int col) {
  
  if(row >= N or col >= N)
    return false;

  if(row == N - 1 and col == N - 1) {
    path[row][col] = 1;
    printMaze(path);
    return false;
  }

  if(maze[row][col] == 1) {
    path[row][col] = 1;
    if(solveMaze(maze, path, row, col + 1))
      return true;
    if(solveMaze(maze, path, row + 1, col))
      return true;
  }

  path[row][col] = 0; // Backtrack.
  return false; 
}

int main() {

  int maze[N][N] = {
    {1, 0, 1, 0, 1}, 
    {1, 1, 1, 1, 1},
    {0, 1, 0, 1, 0},
    {1, 0, 0, 1, 1}, 
    {1, 1, 1, 0, 1}};

  int path[N][N] = {{0}, {0}, {0}};
  solveMaze(maze, path, 0, 0);

  return 0;
}
