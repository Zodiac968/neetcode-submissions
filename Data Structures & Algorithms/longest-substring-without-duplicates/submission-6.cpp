class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int l = 0, r = 0;
        unordered_map<char, int> freq;
        int maxLen = 1;
        // for(int i = 0; i < s.size(); i++){
        //     int j;
        //     for(j = i; j < s.size(); j++){
        //         if(freq.find(s[j]) == freq.end()) freq.insert({s[j], 1});
        //         else break;
        //     }
        //     if(maxLen < j - i) maxLen = j - i;
        //     freq.clear();
        // }
        while(l <= r && r < s.size()){
            if(freq.find(s[r]) == 0 || freq.find(s[r]) == freq.end()){
                freq.insert({s[r], 1});
                r++;
            }
            else{
                char anamoly = s[r];
                while(freq[anamoly] > 0){
                    freq[s[l]]--;
                    l++;
                }
                freq[anamoly] = 1;
                r++;
            }
            maxLen = max(maxLen, r - l);
            cout << l << " " << r << " " << s[r] << endl;
        }

        return maxLen;
    }
};
