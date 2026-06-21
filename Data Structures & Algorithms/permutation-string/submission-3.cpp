class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())  return false;
        int ws = s1.size();
        int l = 0;
        int r = 0;
        int k = 0;
        unordered_map<char, int> freq;
        for(int i = 0; i < s1.size(); i++){
            if(freq.find(s1[i]) == freq.end()) freq.insert({s1[i], 1});
            else freq[s1[i]]++;
        }
        while(r < s2.size()){
            if(freq.find(s2[r]) != freq.end()){
                if(freq[s2[r]] > 0) k++;
                freq[s2[r]]--;
            }
            if(r - l + 1> ws){
                if(freq.find(s2[l]) != freq.end()){
                    freq[s2[l]]++;
                    if(freq[s2[l]] > 0) k--;
                }
                l++;
            }
            cout << s2[l] << " " << s2[r] << " " << k << endl;
            if(k == ws) return true;
            r++;
        }
        return false;
    }
};
