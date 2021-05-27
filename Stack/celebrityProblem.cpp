#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findCelebrity(vector<vector<int> > &M, int n)
{
  if (n <= 1)
    return -1;

  stack<int> s;

  for (int i = 0; i < n; i++)
    s.push(i);

  int person1, person2, celebrity;

  while (s.size() > 1)
  {
    person1 = s.top();
    s.pop();
    person2 = s.top();
    s.pop();

    if (M[person1][person2])
      s.push(person2);
    else
      s.push(person1);
  }

  celebrity = s.top();
  s.pop();

  for (int i = 0; i < n; i++)
    if (i != celebrity and (M[celebrity][i] or !M[i][celebrity]))
      return -1;

  return celebrity;
}

int main()
{
  vector<vector<int> > v;
  vector<int> temp;
  int n, item;

  cout << "Enter Total Person\n";
  cin >> n;

  cout << "Enter Party info\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> item;
      temp.push_back(item);
    }
    v.push_back(temp);
  }

  int celebrity = findCelebrity(v, n);

  if (celebrity != -1)
    cout << "Celebrity is: " << celebrity << endl;
  else
    cout << "No Celebrity Exists." << endl;

  return 0;
}
