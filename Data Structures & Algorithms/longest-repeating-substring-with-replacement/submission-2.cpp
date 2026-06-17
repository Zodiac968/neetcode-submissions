class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l = 0;
        int maxFreq = 0;
        int maxLen = 0;
        for(int r = 0; r < s.size(); r++){
            freq[s[r]]++;
            if(maxFreq < freq[s[r]]) maxFreq = freq[s[r]];
            while(r-l+1 - maxFreq > k){
                freq[s[l]]--;
                l++;
            }
            int len = r-l+1;
            if(len > maxLen) maxLen = len;
        }
        return maxLen;
    }
};
