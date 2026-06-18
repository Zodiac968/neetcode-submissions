class Solution {
public:
    char sep = '`';

    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); i++){
            res += sep;
            for(int j = 0; j < strs[i].size(); j++){
                char c = strs[i][j];
                res += c;
            }
        }
        cout << res << endl;

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int k = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == sep){
                res.push_back("");
                k++;
            }
            else{
                res[k] += s[i];
            }
        }
        return res;
    }
};
