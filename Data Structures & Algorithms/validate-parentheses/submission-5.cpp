class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> pairs = {{')', '('}, {'}', '{'}, {']', '['}};
        string opens = "({[";
        for(int i = 0; i < s.size(); i++){
            if(opens.contains(s[i])) stk.push(s[i]);
            else{
                if(!stk.empty() && pairs[s[i]] == stk.top()) stk.pop();
                else return false;
            }
        }
        if(stk.empty()) return true;
        else return false;
    }
};
