class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> l(heights.size(), 0);
        vector<int> r(heights.size(), -1);
        stack<int> st;
        for(int i = 0; i < heights.size(); i++){
            if(!st.empty() && heights[i] < heights[st.top()]){
                while(!st.empty() && heights[i] < heights[st.top()]){
                    r[st.top()] = i-1;
                    l[i] = l[st.top()];
                    st.pop();
                }
            }
            else if(!st.empty() && heights[i] > heights[st.top()]) l[i] = i;
            else if(!st.empty() && heights[i] == heights[st.top()]) l[i] = l[st.top()];
            st.push(i);
        }
        int top = st.top();
        while(!st.empty()){
            r[st.top()] = top;
            st.pop();
        }
        int maxArea = -1;
        for(int i = 0; i < heights.size(); i++){
            cout << heights[i] << " " << l[i] << " " << r[i] << endl;
            int area = heights[i] * (r[i] - l[i] + 1);
            if(area > maxArea) maxArea = area;
        }
        return maxArea;
    }
};
