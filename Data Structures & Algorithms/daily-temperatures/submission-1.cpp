class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk;
        vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            if(i > 0 && temperatures[i] <= temperatures[i-1]){
                stk.push({temperatures[i-1], i-1});
            }
            else if(i > 0 && temperatures[i] > temperatures[i-1]){
                res[i-1] = 1;
                while(!stk.empty() && stk.top().first < temperatures[i]){
                    res[stk.top().second] = i-stk.top().second;
                    stk.pop();
                }
            }
        }
        return res;
    }
};
