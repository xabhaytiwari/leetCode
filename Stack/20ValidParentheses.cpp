#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class ValidParentheses {
    public:
        bool isValid(string s) {
            stack<char> charStack;
            for(const char c : s) {
                if(c == '(' || c == '{' || c == '[') {
                    charStack.push(c);
                } else {
                    if(charStack.empty()) {
                        return false;
                    }
                    char top = charStack.top(); 
                    charStack.pop();
                     if ((c == ')' && top != '(') ||
                         (c == '}' && top != '{') ||
                         (c == ']' && top != '[')) {
                            return false;
                         }
                }
            }
            return charStack.empty();
        }
};

int main() {
    string s = "()[]{}";
    ValidParentheses solution;
    cout << solution.isValid(s);
    return 0;
}