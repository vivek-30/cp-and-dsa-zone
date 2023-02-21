#include<iostream>
#include<vector>
using namespace std;
 
#define R 5
#define C 5

#define inf INT_MAX
#define minf INT_MIN
#define ll long long int
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define mid(l, r) (l + (r - l) / 2)
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define f(i,s,n) for(ll i = s; i < n; i++)

vector<pair<int, int> > loc {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
 
void print(char graph[R][C]) {
  f(i, 0, R) {
    f(j, 0, C)
      cout<<graph[i][j]<<" ";
    cout<<endl;
  }
}

void changeChar(char graph[R][C], int r, int c, char ch) {  // FloodFill Based Algorithm.
  if(r < 0 or c < 0  or r >= R or c >= C)
    return;

  if(graph[r][c] == 'X' or graph[r][c] == '$')
    return;

  graph[r][c] = ch;
  for(auto i: loc) 
    changeChar(graph, r + i.fi, c + i.se, ch);
}

void modifyGraph(char graph[R][C]) {

  f(i, 0, R) {
    if(graph[i][0] == 'O')  // For 1st Column.
      changeChar(graph, i, 0, '$');
    
    if(graph[i][C-1] == 'O')  // For last Column.
      changeChar(graph, i, C-1, '$');
  }

  f(i, 0, C) {
    if(graph[0][i] == 'O')  // For 1st Row.
      changeChar(graph, 0, i, '$');

    if(graph[R-1][i] == 'O')  // For last Row.
      changeChar(graph, R-1, i, '$');
  }

  f(i, 0, R)
    f(j, 0, C)
      if(graph[i][j] == 'O')
        graph[i][j] = 'X';

  f(i, 0, R)
    f(j, 0, C)
      if(graph[i][j] == '$')
        graph[i][j] = 'O';
}
 
int main() {
  
  char graph[R][C] = {
    {'O', 'X', 'O', 'X', 'X'},
    {'X', 'O', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'O', 'O'},
    {'X', 'X', 'O', 'O', 'X'},
    {'O', 'O', 'X', 'X', 'O'}
  };

  modifyGraph(graph);
  print(graph);
  
  return 0;
}
  