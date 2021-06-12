#include <bits/stdc++.h>
using namespace std;

#define mid(l, r) (l + (r - l) / 2)

bool isFeasible(vector<int> &books, int total, int totalPages)
{
  int sum = 0, current = 1;
  for (int book : books)
  {
    sum += book;
    if (sum > totalPages)
    {
      sum = book;
      current++;
    }
    if (current > total)
      return false;
  }

  return true;
}

int books(vector<int> &books, int total)
{

  int start = INT_MIN, end = 0, mid, ans;
  for (int book : books)
  {
    start = max(start, book);
    end += book;
  }

  if (books.size() < total)
    return -1;

  while (start <= end)
  {
    mid = mid(start, end);
    if (isFeasible(books, total, mid))
    {
      ans = mid;
      end = mid - 1;
    }
    else
      start = mid + 1;
  }

  return ans;
}
