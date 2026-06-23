class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // min a to b * position(a - b)
        int s = heights.size();
        vector<int> bR(s);
        vector<int> bL(s);
        stack<int> stk;
        for(int i = 0; i < s; i++){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                bR[stk.top()] = i-1;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()){   
            bR[stk.top()] = s-1;
            stk.pop();
        }
        for(int i = s-1; i >= 0; i--){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                bL[stk.top()] = i+1;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()){   
            bL[stk.top()] = 0;
            stk.pop();
        }

        for(int i = 0; i < s; i++){
            cout << bR[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < s; i++){
            cout << bL[i] << " ";
        }
        int ma = -1;
        for(int i = 0; i < s; i++){
            int a = heights[i] * (bR[i] - bL[i] + 1);
            if(a > ma) ma = a;
        }
        return ma;
    }
};
