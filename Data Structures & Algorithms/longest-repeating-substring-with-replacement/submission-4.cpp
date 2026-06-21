class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l = 0;
        int r = 0;
        char mfc = s[0];
        while(r < s.size()){
            if(freq.find(s[r]) == freq.end()){
                freq.insert({s[r], 1});
            }
            else{
                freq[s[r]]++;
                if(freq[s[r]] > freq[mfc]) mfc = s[r];
            }

            if(r-l+1 - freq[mfc] > k){
                freq[s[l]]--;
                l++;
            }
            r++;
        }
        return r-l;
    }
};
