#include<iostream>
#include<stack>
using namespace std;

bool hasHigherAndEqualPriority(char top, char curr) {
  if((top == '*' or top == '/' or top == '^' or top == '-' or top == '+') and (curr == '+' or curr == '-'))
    return true;
  return false;
}

char openingPair(char c) {
  if(c == ')') return '(';
  else if(c == ']') return '[';
  else return '{';
}
 
string convertToPostfix(string str) {
  
  int n = str.length();
  string res = "";
  if(n == 0) return res;

  stack<char> s;

  for(char c: str) {
    if(c == '+' or c == '-' or c == '*' or c == '/' or c == '^') {
      while(not s.empty() and hasHigherAndEqualPriority(s.top(), c)) {
        res += s.top();
        s.pop();
      }
      s.push(c);
    }
    else if(c == '(' or c == '{' or c == '[')
      s.push(c);
    else if(c == ')' or c == '}' or c == ']') {
      while(not s.empty() and s.top() != openingPair(c)) {
        res += s.top();
        s.pop();
      }
      if(not s.empty())
        s.pop();
    }
    else res += c;
  }

  while(not s.empty()) {
    res += s.top();
    s.pop();
  }

  return res;
}
 
int main() {
  
  string str;
  cout<<"Enter a infix expression"<<endl;
  cin>>str;
  
  cout<<"Postfix expression is: "<<convertToPostfix(str)<<endl;
  
  return 0;
}
  