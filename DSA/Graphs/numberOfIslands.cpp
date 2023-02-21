#include <bits/stdc++.h>
using namespace std;

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
#define pqmin priority_queue<int, vi, greater<int>>
#define f(i, s, n) for (ll i = s; i < n; i++)

int R = 0, C = 0;

void captureIsland(vector<vector<char>> &grid, int r, int c)
{
  if (r < 0 or c < 0 or r >= R or c >= C)
    return;
  if (grid[r][c] == '0')
    return;

  grid[r][c] = '0';
  captureIsland(grid, r - 1, c);
  captureIsland(grid, r + 1, c);
  captureIsland(grid, r, c - 1);
  captureIsland(grid, r, c + 1);
}

int numIslands(vector<vector<char>> &grid)
{
  R = grid.size();
  C = grid[0].size();
  int ans = 0;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (grid[i][j] == '1')
      {
        captureIsland(grid, i, j);
        ans++;
      }
    }
  }

  return ans;
}
