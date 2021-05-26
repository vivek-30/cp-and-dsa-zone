#include <iostream>
#include<stack>
using namespace std;

bool isMatching(char exp1, char exp2)
{
  if ((exp1 == '(' and exp2 == ')') or (exp1 == '[' and exp2 == ']') or (exp1 == '{' and exp2 == '}'))
    return true;

  return false;
}

bool isValid(string s)
{

  if (s.length() <= 1)
    return s.length() ? false : true;

  char exp;
  stack<char> st;

  for (int i = 0; i < s.length(); i++)
  {
    exp = s[i];
    if (exp == '(' or exp == '{' or exp == '[')
      st.push(exp);
    else if (!st.empty() and isMatching(st.top(), exp))
      st.pop();
    else
      return false;
  }

  return st.empty();
}

int main()
{
  string str = "{()(){[({()})]}}";
  if(isValid(str))
    cout<<"Valid\n";
  else cout<<"Invalid\n";

  return 0;
}
