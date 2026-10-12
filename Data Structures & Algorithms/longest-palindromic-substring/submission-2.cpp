class Solution {
public:
    string longestPalindrome(string s) {
        int l = 0, r = 0, c = 0;
        int res = 0;
        int resLen = 1;
        string transformed;
        for(int i = 0; i < s.size(); i++){
            transformed += "#";
            transformed += s[i];
        }
        transformed += "#";
        vector<int> p(transformed.size(), 1);
        for(int i = 0; i < transformed.size(); i++){
            int lp = i-1;
            int rp = i+1;
            int currLen = 1;
            if(i < r){
                int mirror = 2*c - i;
                lp = i-(p[mirror]-1)/2 - 1;
                rp = i+(p[mirror]-1)/2 + 1;
                currLen = p[mirror];
                if(rp > r){
                    int diff = rp - r;
                    rp = r+1;
                    lp += diff-1;
                    currLen -= (diff-1)*2;
                }
            }
            while(lp >= 0 && rp < transformed.size() && transformed[lp] == transformed[rp]){
                currLen += 2;
                if(rp > r){
                    l = lp;
                    r = rp;
                    c = i;
                }
                lp--;
                rp++;
            }
            p[i] = currLen;
            // cout << i << " " << currLen << endl;
            if(currLen > resLen){
                res = i;
                resLen = currLen;
            }
        }
        string resS = transformed.substr(res-(resLen-1)/2, resLen);
        resS.erase(remove(resS.begin(), resS.end(), '#'), resS.end());
        return resS;
        return "";
    }
};
