class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {{')', '('}, {'}', '{'}, {']', '['}};
        int close = 0, open = 0;
        for(int i = 0; i < s.size(); i++){
            if(pairs.find(s[i]) != pairs.end()){
                close++;
                while(!st.empty() && st.top() != pairs[s[i]]) st.pop();
                if(st.empty()) return false;
                st.pop();
            }
            else{
                open++;
                st.push(s[i]);
            }
        }
        if(!st.empty()) return false;
        if(open != close) return false;
        return true;
    }
};
