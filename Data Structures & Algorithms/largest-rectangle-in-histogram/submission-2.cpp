class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
        st.push(-1);
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int h = st.top();
                st.pop();
                int area = heights[h] * (i-1 - st.top());
                if(area > maxArea) maxArea = area;
            }
            st.push(i);
        }
        return maxArea;
    }
};
