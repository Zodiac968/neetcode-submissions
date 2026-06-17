class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        string res = "";
        unordered_map<char, int> freq;
        for(int i = 0; i < t.size(); i++){
            freq[t[i]]++;
        }
        int k = freq.size();
        for(int r = 0; r < s.size(); r++){
            freq[s[r]]--;
            if(freq[s[r]] == 0) k--;
            if(k == 0){
                while(freq[s[l]] != 0){
                    freq[s[l]]++;
                    l++;
                }
                string sub = s.substr(l, r-l+1);
                if(sub.size() < res.size() || res.empty()) res = sub;
                freq[s[l]]++;
                l++;
                k++;
            }
        }
        return res;
    }
};
