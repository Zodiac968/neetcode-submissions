class Solution {
public:

    void generate(int open, int close, vector<string>& res, string& curr){
        if(open == 0 && close == 0){
            //cout << curr << endl;
            res.push_back(curr);
            return;
        }
        else if(open == 0){
            curr += ")";
            close--;
            generate(open, close, res, curr);
            close++;
            curr.pop_back();
        }else{
            curr += "(";
            open--;
            generate(open, close, res, curr);
            open++;
            curr.pop_back();
            if(close > open){
                curr += ")";
                close--;
                generate(open, close, res, curr);
                close++;
                curr.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        generate(n, n, res, curr);
        return res;
    }
};
