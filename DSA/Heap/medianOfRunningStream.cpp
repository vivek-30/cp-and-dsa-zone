#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> pqmax;
priority_queue<int, vector<int>, greater<int>> pqmin;

void addValue(int x)
{
  if (pqmax.empty() and pqmin.empty())
    pqmax.push(x);
  else if (pqmax.size() > pqmin.size())
  {
    if (pqmax.top() <= x)
      pqmin.push(x);
    else
    {
      pqmin.push(pqmax.top());
      pqmax.pop();
      pqmax.push(x);
    }
  }
  else
  {
    if (x <= pqmin.top())
      pqmax.push(x);
    else
    {
      pqmax.push(pqmin.top());
      pqmin.pop();
      pqmin.push(x);
    }
  }
}

double findMedian()
{
  if (pqmax.size() == 0 and pqmin.size() == 0)
    return -1;

  if (pqmax.size() > pqmin.size())
    return pqmax.top();
  else if (pqmin.size() > pqmax.size())
    return pqmin.top();
  else
    return ((pqmin.top() + pqmax.top()) / 2.0);
}

int main()
{

  int value, choice;

  cout << "Enter choice.\n1.Add value.\n2.find Median.\n3.Exit.\n";
  cin >> choice;

  while (choice)
  {
    switch (choice)
    {
    case 1:
      cout << "Enter value.\n";
      cin >> value;
      addValue(value);
      break;

    case 2:
      cout << "Median is: " << findMedian() << endl;
      break;

    case 3:
      return 0;

    default:
      cout << "Wrong choice.\n";
    }

    cout << "Enter Your Choice.\n";
    cin >> choice;
  }

  return 0;
}
