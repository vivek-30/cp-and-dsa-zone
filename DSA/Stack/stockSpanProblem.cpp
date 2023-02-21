#include <iostream>
#include <stack>
using namespace std;

class StockSpanner
{
private:
  stack<pair<int, int> > s; // Pair of price, days

public:
  int next(int price)
  {
    int ans = 1;
    while (!s.empty() and price >= s.top().first)
    {
      ans += s.top().second;
      s.pop();
    }

    s.push(make_pair(price, ans));
    return ans;
  }
};
