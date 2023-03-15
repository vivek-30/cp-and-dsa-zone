/**
 * @param {number} numRows
 * @return {number[][]}
 */

const solve = (curr, ans, n) => {
  if(curr == n) return;

  const res = [];
  for(let i = 1; i <= curr-1; i++) {
    res.push(ans[curr-1][i-1]+ans[curr-1][i]);
  }
  ans.push([1, ...res, 1]);
  solve(curr+1, ans, n);
}

var generate = function(numRows) {
  if(numRows <= 2) {
    return numRows === 1 ? [[1]] : [[1], [1, 1]];
  }

  const ans = [[1], [1, 1]];
  solve(2, ans, numRows);
  return ans;
};
