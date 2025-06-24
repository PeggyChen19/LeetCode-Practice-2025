class MyQueue {
public:
    stack<int> original;
    stack<int> reversed;
    MyQueue() {}
    
    void push(int x) {
        original.push(x);
    }
    
    int pop() {
        int top = peek();
        reversed.pop();
        return top;
    }
    
    int peek() {
        if (reversed.empty()) { // reversed is empty -> migrate all data from original
            while (!original.empty()) {
                int original_top = original.top();
                original.pop();
                reversed.push(original_top);
            }
        }
        return reversed.top();
    }
    
    bool empty() {
        return original.empty() && reversed.empty();
    }
};
/*
Queue: First in first out
Stack: First in last out (push to top, peek/pop from top, size, empty)

original stack: 5 6 7
reversed stack: 4 3 2 1
When reversed is empty, migrate all data from original (reverse it)
*/