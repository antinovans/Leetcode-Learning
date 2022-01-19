/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
#include <iostream>
#include <vector>
using namespace std;
class MyCircularQueue {
public:
    MyCircularQueue(int k): _size(k) {
        mydata = new vector<int>(k);
    }
    ~MyCircularQueue(){
        delete mydata;
        mydata = nullptr;
    }
    bool enQueue(int value) {
        if(_currentSize >= _size)
            return false;
        (*mydata)[(_beginIndex+_currentSize) % _size] = value;
        _currentSize++;
        return true;
    }
    
    bool deQueue() {
        if(_currentSize == 0)
            return false;
        _beginIndex = (_beginIndex + 1)% _size;
        _currentSize--;
        return true;
    }
    
    int Front() {
        if(_currentSize == 0)
            return -1;
        return (*mydata)[_beginIndex];
    }
    
    int Rear() {
        if(_currentSize == 0)
            return -1;
        int tail = (_beginIndex+ _currentSize - 1) % _size;
        return (*mydata)[tail];
    }
    
    bool isEmpty() {
        return _currentSize == 0;
    }
    
    bool isFull() {
        return _currentSize == _size;
    }
private:
    int _size = 0;
    int _currentSize = 0;
    vector<int>* mydata;
    int _beginIndex = 0;
};

int main()
{
    MyCircularQueue a(3);
    a.enQueue(1);
    a.enQueue(2);
    a.enQueue(3);
    a.enQueue(4);
    a.deQueue();
    a.enQueue(4);
}
