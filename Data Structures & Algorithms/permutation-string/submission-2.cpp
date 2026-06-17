class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq1;
        int l = 0;
        for(int r = 0; r < s1.size(); r++){
            freq1[s1[r]]++;
        }
        int k = freq1.size();
        for(int r = 0; r < s2.size(); r++){
            freq1[s2[r]]--;
            if(r-l+1 > s1.size()){
                freq1[s2[l]]++;
                if(freq1[s2[l]] > 0) k++;
                l++;
            }
            if(freq1[s2[r]] == 0) k--;
            cout << s2.substr(l, r-l+1) << " " << k << endl;
            if(k == 0) return true;
        }
        return false;
    }
};
