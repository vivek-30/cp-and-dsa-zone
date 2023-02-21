#include<iostream>
#include<stack>
using namespace std;

bool hasHigherAndEqualPriority(char top, char curr) {
  if((top == '*' or top == '/' or top == '^' or top == '-' or top == '+') and (curr == '+' or curr == '-'))
    return true;
  return false;
}

char oppositeBrace(char c) {
  if(c == ')') return '(';
  else if(c == ']') return '[';
  else if(c == '}') return '{';
  else if(c == '(') return ')';
  else if(c == '[') return ']';
  else return '}';
}

char openingPair(char c) {
  if(c == ')') return '(';
  else if(c == ']') return '[';
  else return '{';
}
 
string convertToPrefix(string str) {
  
  int n = str.length();
  string res = "";
  char e;
  if(n == 0) return res;

  reverse(str.begin(), str.end());
  for(int i=0; i<str.length(); i++) { // Note -> after reversing original string parentheses also get reversed.
    e = str[i];
    if(e == '(' or e == '[' or e == '{' or e == ')' or e == ']' or e == '}')
      str[i] = oppositeBrace(e);
  }

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

  reverse(res.begin(), res.end()); // get desired Prefix expression by reversing.
  reverse(str.begin(), str.end()); // revert back orginal string.
  for(int i=0; i<str.length(); i++) {
    e = str[i];
    if(e == '(' or e == '[' or e == '{' or e == ')' or e == ']' or e == '}')
      str[i] = oppositeBrace(e);
  }

  return res;
}
 
int main() {
  
  string str;
  cout<<"Enter a infix expression"<<endl;
  cin>>str;
  
  cout<<"Prefix expression is: "<<convertToPrefix(str)<<endl;
  
  return 0;
}
  