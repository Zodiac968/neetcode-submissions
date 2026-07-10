class Solution {
public:
    vector<char> getChars(char digit){
        if(digit == '2') return {'a', 'b', 'c'};
        if(digit == '3') return {'d', 'e', 'f'};
        if(digit == '4') return {'g', 'h', 'i'};
        if(digit == '5') return {'j', 'k', 'l'};
        if(digit == '6') return {'m', 'n', 'o'};
        if(digit == '7') return {'p', 'q', 'r', 's'};
        if(digit == '8') return {'t', 'u', 'v'};
        if(digit == '9') return {'w', 'x', 'y', 'z'};
    }

    void stringComb(string &digits, vector<string> &res, string &base, int index){
        if(index < digits.size()){
            vector<char> letters = getChars(digits[index]);
            for(int i = 0; i < letters.size(); i++){
                base += letters[i];
                stringComb(digits, res, base, index+1);
                base.pop_back();
            }
        }else{
            if(base.empty()) return;
            res.push_back(base);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string base;
        stringComb(digits, res, base, 0);
        return res;
    }
};
