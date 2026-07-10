class Solution {
public:
    bool isPalindrome(string s){
        int l = 0;
        int r = s.size()-1;
        while(l <= r){
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }

    void subset(string& s, vector<vector<string>>& res, vector<string>& base, int index){
        if(index < s.size()){
            string temp;
            temp += s[index];
            base.push_back(temp);
            subset(s, res, base, index+1);
            base.pop_back();

            if(!base.empty()){
                temp = base[base.size()-1];
                temp += s[index];
                base.pop_back();
                base.push_back(temp);
                subset(s, res, base, index+1);
                base.pop_back();
                temp.pop_back();
                base.push_back(temp);
            }
        }
        else{
            bool palindrome = true;
            for(int i = 0; i < base.size(); i++){
                //cout << base[i] << " ";
                if(!isPalindrome(base[i])){
                    palindrome = false;
                    break;
                } 
            }
            if(palindrome) res.push_back(base);
            //cout << endl;
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> base;
        subset(s, res, base, 0);
        return res;
    }
};
