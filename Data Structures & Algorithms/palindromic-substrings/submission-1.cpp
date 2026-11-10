class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            //Odd
            int l = i;
            int r = i;
            while(l >= 0 && r < s.size()){
                if(s[l] == s[r]) {
                    count++;
                    l--;
                    r++;
                }
                else break;
            }
            //EVEN
            l = i;
            r = i+1;
            while(l >= 0 && r < s.size()){
                if(s[l] == s[r]) {
                    count++;
                    l--;
                    r++;
                }
                else break;
            }
        }
        return count;
    }
};
