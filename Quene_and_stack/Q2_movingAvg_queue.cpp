#include <iostream>
#include <queue>
#include <algorithm>
class MovingAverage {
public:
    MovingAverage(int size): _size(size) {

    }
    
    double next(int val) {
        if(myqueue.size() < _size){
            myqueue.push(val);
        }
        else{
            sum -= myqueue.front();
            myqueue.pop();
            myqueue.push(val);
        }
        sum += val;
        std::cout << "size:"<<myqueue.size() << std::endl;
        return 1.0 * sum /myqueue.size() ;
    }

private:
    std::queue<int> myqueue;
    int _size = 0;
    double sum = 0;
};
int main()
{
    MovingAverage myqueue(3);
    std::cout << myqueue.next(1) <<"\n";
    std::cout << myqueue.next(10) <<"\n";
    std::cout << myqueue.next(3) <<"\n";
    std::cout << myqueue.next(5) <<"\n";
}