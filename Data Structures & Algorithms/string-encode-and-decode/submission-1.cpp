class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto s : strs){
            res += to_string(s.length());
            res += "^";
            res += s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string temp;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '^'){
                int n = stoi(temp);
                res.push_back(s.substr(i+1, n));
                i += n;
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        return res;
    }
};
