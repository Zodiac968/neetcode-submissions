class MinStack {
public:
    stack<int> st;
    stack<int> ex;

    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) ex.push(val);
        else if(val < ex.top()) ex.push(val);
        else ex.push(ex.top());
        st.push(val);
    }
    
    void pop() {
        st.pop();
        ex.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ex.top();        
    }
};
