#include <iostream>
#include <stack>
#include <string>
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> parentheses;
        for(auto i : s){
            if(i=='(' || i == '{' || i == '['){
                parentheses.push(i);
            }
            else{
                if(parentheses.empty() || (i == ')' && parentheses.top() != '(')||(i == ']' && parentheses.top() != '[')||(i == '}' && parentheses.top() != '{')){
                    return false;
                }
                parentheses.pop();
            }
        }
        return parentheses.empty();
    }
};