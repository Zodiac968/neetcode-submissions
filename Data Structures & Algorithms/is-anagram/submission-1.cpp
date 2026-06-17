class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq(26);
        for(char c : s){
            if(freq.find(c) == freq.end()) freq[c] = 1;
            else{
                freq[c] += 1;
            }
        }
        for(char c : t){
            if(freq.find(c) == freq.end()) return false;
            else{
                freq[c] -= 1;
            }
        }
        for(auto &p : freq){
            if(p.second != 0) return false;
        }
        return true;
    }
};
