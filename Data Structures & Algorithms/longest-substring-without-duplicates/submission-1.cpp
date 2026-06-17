class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, max = 0;
        unordered_map<char, int> freq;
        for(int r = 0; r < s.size(); r++){
            if(++freq[s[r]] > 1){
                while(s[l] != s[r]){
                    freq[s[l]] = 0;
                    l++;
                }
                freq[s[l]] = 1;
                l++;
            }
            int length = r-l+1;
            if(max < length) max = length;
        }
        return max;
    }
};
