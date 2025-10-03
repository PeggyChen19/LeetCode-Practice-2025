class MinStack {
private:
    stack<int> st;
    stack<int> decreasing;

public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (decreasing.empty() || val <= decreasing.top()) {
            decreasing.push(val);
        }
    }
    
    void pop() {
        if (st.top() == decreasing.top()) {
            decreasing.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return decreasing.top();
    }
};

/*
1. normal stack: 2 3 1 4 5 6 0
2. decreasing stack: 2 1 0
*/