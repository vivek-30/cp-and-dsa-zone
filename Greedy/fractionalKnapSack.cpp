#include <iostream>
using namespace std;

class Item
{
public:
  int price, weight;

  Item()
  {
    price = weight = 0;
  }

  Item(int _price, int _weight)
  {
    price = _price;
    weight = _weight;
  }
};

bool compare(Item a, Item b) {
  double first = a.price/a.weight;
  double second = b.price/b.weight;
  return first > second;
}

double findProfit(Item arr[], int n, int capacity) {

  if(n <= 0) return 0;

  sort(arr, arr + n, compare);
  double profit = 0;

  for(int i=0; i<n; i++) {
    if(arr[i].weight <= capacity) {
      capacity -= arr[i].weight;
      profit += arr[i].price;
    } else {
      profit += ((double)arr[i].price/(double)arr[i].weight)*capacity;
      break;
    }
  }

  return profit;
}

int main()
{

  Item arr[] = {{40, 5}, {24, 4}, {30, 6}, {21, 7}, {12, 6}};
  int capacity = 20;
  int n = sizeof(arr)/sizeof(arr[0]);

  cout<<findProfit(arr, n, capacity)<<endl;
  return 0;
}
