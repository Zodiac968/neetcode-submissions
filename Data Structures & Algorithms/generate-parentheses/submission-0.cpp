class Solution {
public:
    bool validate(string c){
        stack<char> stk;
        for(int i = 0; i < c.size(); i++){
            if(c[i] == '(') stk.push(c[i]);
            else {
                if(stk.empty()) return false;
                stk.pop();
            }
        }
        if(stk.empty()) return true;
        return false;
    }

    void generate(int open, int close, vector<string>& res, string& curr){
        if(open == 0 && close == 0){
            //cout << curr << endl;
            if(validate(curr)) res.push_back(curr);
            return;
        }
        else if(open == 0){
            curr += ")";
            close--;
            generate(open, close, res, curr);
            close++;
            curr.pop_back();
        }
        else if(close == 0){
            curr += "(";
            open--;
            generate(open, close, res, curr);
            open++;
            curr.pop_back();
        }
        else{
            for(int i = 0; i < 2; i++){
                if(i == 0){
                    curr += "(";
                    open--;
                    generate(open, close, res, curr);
                    curr.pop_back();
                    open++;
                }else{
                    curr += ")";
                    close--;
                    generate(open, close, res, curr);
                    curr.pop_back();
                    close++;
                }
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
