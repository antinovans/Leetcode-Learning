#include <iostream>
#include <stack>
#include <string>
#include <vector>
class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> operands;
        for(auto token:tokens){
            if(operands.size()>1 && (token=="+" ||token=="-" ||token=="*" ||token=="/")){
                int op1 = operands.top();
                operands.pop();
                int op2 = operands.top();
                operands.pop();
                switch (token[0])
                {
                case '+':
                    operands.push(op2+op1);
                    break;
                case '-':
                    operands.push(op2-op1);
                    break;
                case '*':
                    operands.push(op2*op1);
                    break;
                case '/':
                    operands.push(op2/op1);
                    break;
                }
            }
            else{
                operands.push(std::stoi(token));
            }
        }
        return operands.top();
    }
};
int main(){
    std::vector<std::string> mystring = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution solu;
    std::cout << solu.evalRPN(mystring);
}