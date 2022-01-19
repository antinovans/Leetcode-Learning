// Input
// ["MovingAverage", "next", "next", "next", "next"]
// [[3], [1], [10], [3], [5]]
// Output
// [null, 1.0, 5.5, 4.66667, 6.0]

// Explanation
// MovingAverage movingAverage = new MovingAverage(3);
// movingAverage.next(1); // return 1.0 = 1 / 1
// movingAverage.next(10); // return 5.5 = (1 + 10) / 2
// movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
// movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
#include <iostream>
#include <deque>
class MovingAverage {
public:
    MovingAverage(int size): _size(size) {

    }
    
    double next(int val) {
        if(myqueue.size() < _size){
            myqueue.push_back(val);
        }
        else{
            myqueue.pop_front();
            myqueue.push_back(val);
        }
        std::cout << "size:"<<myqueue.size() << std::endl;
        std::cout << "avg: "<<avg() << std::endl;
        return avg();
    }

    double avg(){
        int sum;
        for(int num:myqueue){
            sum += num;
        }
        return (1.0 * sum / myqueue.size());
    }
private:
    std::deque<int> myqueue;
    int _size = 0;
};
int main()
{
    MovingAverage myqueue(3);
    myqueue.next(1);
    myqueue.next(10);
    myqueue.next(3);
    myqueue.next(5);

}