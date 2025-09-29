class MyCircularQueue {
private:
    int start = 0;
    int end = -1;
    int count = 0;
    vector<int> queue;

public:
    MyCircularQueue(int k) {
        queue = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        end = (end + 1) % queue.size(); // make one space
        queue[end] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        start = (start + 1) % queue.size(); // clear one space
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        else return queue[start];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        else return queue[end];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == queue.size();
    }
};

/*
implement it using vector
two pointer -> start & end
moving the start & end based on operation, if exceeding vector tail -> move to vector head by % vector.size()
*/