class MinStack {
public:
    vector<int> stk;
    vector<int> min;
    MinStack() {
    }
    
    void push(int val) {
        if(stk.empty() || min[min.size()-1] >= val) min.push_back(val);
        stk.push_back(val);
    }
    
    void pop() {
        if(!min.empty() && stk[stk.size()-1] == min[min.size()-1]) min.pop_back();
        stk.pop_back();
    }
    
    int top() {
        return stk[stk.size()-1];
    }
    
    int getMin() {
        return min[min.size()-1];
    }
};
