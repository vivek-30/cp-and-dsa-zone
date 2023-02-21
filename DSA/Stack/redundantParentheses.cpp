#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch) {
    if(ch == '+' or ch == '-' or ch == '*' or ch == '/')
        return true;
    return false;
}

char pairedMatch(char ch) {
    if(ch == ')')
        return '(';
    else if(ch == ']')
        return '[';
    else return '{';
}

bool checkRedundantParentheses(char exp[], int len) {
    if(len <= 1)
        return false;
        
    int i = 0;
    char ch;
    stack<char> s;
    bool isSomething = false;
    
    while(i < len) {
        ch = exp[i];
        
        if(ch != ')' and ch != ']' and ch != '}')
            s.push(ch);
        else {
            while(!s.empty() and s.top() != pairedMatch(ch)) {
                if(isOperator(s.top()))
                    isSomething = true;
                s.pop();
            }
            
             if(!isSomething)
                return true;
            if(!s.empty())
                s.pop(); // Remove last closing brace.
        }
        isSomething = false;
        i++;
    }
    return false;
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int t;
	cin>>t;
	while(t--) {
	    char exp[1000000];
	    cin>>exp;
	    if(checkRedundantParentheses(exp, strlen(exp)))
	        cout<<"Yes\n";
	   else cout<<"No\n";
	}
	return 0;
}
