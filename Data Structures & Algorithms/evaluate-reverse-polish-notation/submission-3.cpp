class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        string ops = "+-*/";
        int eval;
        for(int i = 0; i < tokens.size(); i++){
            if(ops.contains(tokens[i])){
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                switch(tokens[i][0]){
                    case '+':
                        eval = a + b;
                        break;
                    case '-':
                        eval = a - b;
                        break;
                    case '*':
                        eval = a * b;
                        break;
                    case '/':
                        eval = a / b;
                        break;
                }
                stk.push(eval);
            }
            else{
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
