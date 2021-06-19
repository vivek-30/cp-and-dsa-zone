#include <iostream>
#include <vector>
using namespace std;

int minCoin(vector<int> &coins, int amount)
{
  int n = coins.size();
  if (amount < 0 or (n == 0 and amount > 0))
    return -1;
  if (amount == 0)
    return 0;

  sort(coins.begin(), coins.end(), greater<int>());
  int ans = 0;

  for (int coin : coins)
  {
    while (coin <= amount)
    {
      amount -= coin;
      ans++;
    }
  }

  return amount == 0 ? ans : -1;
}

int main()
{

  vector<int> coins{1, 2, 5, 10, 20, 50, 100, 500, 100};
  int t, k;
  cin >> t;
  while (t--)
  {
    cin >> k;
    cout << minCoin(coins, k) << endl;
  }

  return 0;
}
