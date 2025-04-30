class Element {
public:
    int val, min;
    Element* next;
    Element(int val, int min, Element* next): val(val), min(min), next(next) {}
};

class MinStack {
private:
    Element* top_element;
public:
    MinStack() {
        top_element = new Element(0, INT_MAX, nullptr);
    }
    
    void push(int val) {
        Element* new_element = new Element(val, min(val, top_element->min), top_element);        
        top_element = new_element;
    }
    
    void pop() {
        Element* to_remove = top_element;
        top_element = top_element->next;
        delete to_remove;
    }
    
    int top() {
        return top_element->val;
    }
    
    int getMin() {
        return top_element->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 
push, pop, top -> normal stack
min -> for each element, we can record the min from bottom~element
    -> when we pop, the min record of remaining elements won't affect

we can use build-in stack or create our own via linked list
*/