class MyStack {
private:
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }
    
    int pop() {
        int front = q.front();
        q.pop();
        return front;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/*
stack -> first in last out
queue -> first in first out

One queue:
push: the last element should be firstly accessible -> O(n)
1. move the last to the head of queue
2. pop all element before last and push again 
pop: simply pop front -> O(1)

Two queue:
push: simply push -> O(1)
pop: move all elements except the last one to another queue, get the last one -> O(n)
*/