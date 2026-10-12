class Solution {
public:
    string longestPalindrome(string s) {
        int res = 0;
        int resLen = 1;

        for(int i = 0; i < s.size(); i++){
            int lp = i-1;
            int rp = i+1;
            int currLen = 1;
            //Odd
            while(lp >= 0 && rp < s.size() && s[lp] == s[rp]){
                lp--;
                rp++;
                currLen+=2;
            }
            if(currLen > resLen){
                res = i;
                resLen = currLen;
            }
            //Even
            lp = i;
            rp = i+1;
            currLen = 0;
            while(lp >= 0 && rp < s.size() && s[lp] == s[rp]){
                lp--;
                rp++;
                currLen += 2;
            }
            if(currLen > resLen){
                res = i;
                resLen = currLen;
            }
        }
        if(resLen % 2 == 1) return s.substr(res-((resLen-1)/2.0), resLen);
        return s.substr(res-(resLen/2.0)+1, resLen);
    }
};
