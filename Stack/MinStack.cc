class MinStack {
public:
    stack<int> mainStack;
    stack<int> aidStack;
    
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        mainStack.push(x);
        if(aidStack.empty())
            aidStack.push(x);
        else{
            int currMin = aidStack.top();
            if(currMin <= x)
                aidStack.push(currMin);
            else
                aidStack.push(x);
        }
    }
    
    void pop() {
        mainStack.pop();
        aidStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return aidStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
