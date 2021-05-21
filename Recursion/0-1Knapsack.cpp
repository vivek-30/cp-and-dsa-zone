#include<iostream>
using namespace std;

int findProfit(int prices[], int weights[], int total, int item, int capacity) {

  if(capacity <= 0 or total <= 0 or item >= total)
    return 0;

  int profit_1 = 0, profit_2 = 0;
    
  if(capacity - weights[item] >= 0) {
    profit_1 = prices[item] + findProfit(prices, weights, total, item + 1, capacity - weights[item]);
    profit_2 = findProfit(prices, weights, total, item + 1, capacity);
  }
  else return findProfit(prices, weights, total, item + 1, capacity);

  return max(profit_1, profit_2);
}

int main() {

  int capacity = 8;
  int prices[] = { 2, 4, 5, 7, 1, 4 };
  int weights[] = { 1, 3, 4, 7, 2, 4 };

  cout<<"Max. Profit is: "<<findProfit(prices, weights, 6, 0, capacity)<<endl;
  return 0;
}
