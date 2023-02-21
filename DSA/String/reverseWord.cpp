#include <iostream>
#include <stack>
using namespace std;

string reverseWords(string s)
{

  if (!s.length())
    return " ";

  string word = "", sentence = "";
  stack<string> wordList;

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == ' ')
    {
      if (word.length())
      {
        wordList.push(word);
        word.clear();
      }
    }
    else
      word += s[i];
  }

  if (word.length())
  { // Push last word.
    wordList.push(word);
  }

  while (!wordList.empty())
  {
    word = wordList.top();
    wordList.pop();
    sentence += word;
    sentence += " ";
  }

  sentence.pop_back(); // Remove last extra space.

  return sentence;
}

string reverseWords2(string s)
{

  if (!s.length())
    return " ";

  string word = "", sentence = "";

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == ' ')
    {
      if (word.length())
      {
        sentence.insert(0, " " + word);
        word.clear();
      }
    }
    else
      word += s[i];
  }

  if (word.length()) // Add the last word.
    sentence.insert(0, word);
  else
    sentence = sentence.substr(1); // Remove starting space

  return sentence;
}

int main()
{

  string str1 = " my    Name is Vivek   !!!";
  cout << reverseWords(str1) << endl;

  string str2 = "my program to  reverse the word";
  cout << reverseWords(str2) << endl;

  return 0;
}