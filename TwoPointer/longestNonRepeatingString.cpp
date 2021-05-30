#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      
      int n = s.length();
      
      if(n <= 1)
        return n;
      
      unordered_map<char, bool> lookup;
      int current=0, ans=0, i = 0;
      
      for(int j=0; j<n; j++) {
        
        while(lookup[s[j]]) { // while string has duplicate characters shrink from back.
          lookup[s[i]] = false;
          i++;
          current--; // decrease current length till duplicate character.
        }
        
        current++;
        lookup[s[j]] = true;
        ans = max(ans, current);
      }
      
      return ans;
    }
};
