#include <vector>
#include <iostream>
class MinStack {
public:
    MinStack() {
        
    }
    MinStack(std::vector<int> input) {
        for(auto i : input){
            if(minimum.empty() || i <= getMin()){
                minimum.push_back(i);
            }
            myStack.push_back(i);
        }
    }

    void push(int val) {
        if(minimum.empty() || val <= getMin()){
            minimum.push_back(val);
        }
        myStack.push_back(val);
    }
    
    void pop() {
        if(myStack.back() == getMin()) minimum.pop_back();
        myStack.pop_back();
    }
    
    int top() {
        return myStack.back();
    }
    
    int getMin() {
        return minimum.back();
    }
private:
    std::vector<int> myStack;
    std::vector<int> minimum;
};
int main(){

    MinStack* obj = new MinStack({2,3,4,5,9,-10,-2});
    obj->push(5);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    std::cout << param_3 <<std::endl;
    std::cout << param_4 <<std::endl;
}