#include<iostream>
using namespace std;
#define N 8

void printTour(int chess[N][N]) {
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++)
      cout<<chess[i][j]<<" ";
    cout<<endl;
  }
}

bool canPlace(int chess[][N], int row, int col) {
  if(row < 0 or col < 0 or row >= N or col >= N or chess[row][col])
    return false;
  return true;
}

bool makeTour(int chess[][N], int row, int col, int num) {

  if(num == ((N * N) + 1)) {
    chess[row][col] = num;
    printTour(chess);
    return true;
  }

  if(canPlace(chess, row, col)) {
    
    chess[row][col] = num;

    if(makeTour(chess, row - 2, col + 1, num + 1))
      return true;
    if(makeTour(chess, row - 1, col + 2, num + 1))
      return true;
    if(makeTour(chess, row + 1, col + 2, num + 1))
      return true;
    if(makeTour(chess, row + 2, col + 1, num + 1))
      return true;
    if(makeTour(chess, row + 2, col - 1, num + 1))
      return true;
    if(makeTour(chess, row + 1, col - 2, num + 1))
      return true;
    if(makeTour(chess, row - 1, col - 2, num + 1))
      return true;
    if(makeTour(chess, row - 2, col - 1, num + 1))
      return true;

    chess[row][col] = 0;
  }

  return false;
}

int main() {

  int chess[N][N];
  memset(chess, 0, sizeof(chess));
  makeTour(chess, 0, 0, 1);

  return 0;
}
