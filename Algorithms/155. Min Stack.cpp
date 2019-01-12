class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x);
    
    void pop();
    
    int top();
    
    int getMin();
private:
    stack<int> _stack;
    stack<int> _min_elements;
};

void MinStack::push(int x) {
    _stack.push(x);
    if (_min_elements.empty() || x <= _min_elements.top()) {
        _min_elements.push(x);
    }
}

void MinStack::pop() {
    int x = _stack.top();
    _stack.pop();    
    if (x == _min_elements.top()) {
        _min_elements.pop();
    }
}

int MinStack::top() {
    return _stack.top();
}

int MinStack::getMin() {
    return _min_elements.top();
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */