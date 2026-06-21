class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        unordered_map<char, int> freq2;
        for(int i = 0; i < t.size(); i++){
            if(freq.find(t[i]) == freq.end()) freq.insert({t[i], 1});
            else freq[t[i]]++;
        }
        string res = "";
        int k = 0;
        int l = 0;
        int r = 0;
        int prevr = -1;
        while(l <= r && r < s.size()){
            if(k == freq.size()){
                if(freq.find(s[l]) != freq.end() && freq[s[l]] >= freq2[s[l]]){
                    cout << s.substr(l, r-l+1) << " " << s[l] << " " << s[r] << endl;
                    if(r-l+1 < res.size() || res.empty())
                        res = s.substr(l, r-l+1);
                    r++;
                    k--;
                }
                freq2[s[l]]--;
                l++;
            }
            else{
                if(freq2.find(s[r]) == freq2.end()) freq2.insert({s[r], 1});
                else freq2[s[r]]++;

                if(freq.find(s[r]) != freq.end() && freq2[s[r]] == freq[s[r]]){
                    k++;
                }
                if(k != freq.size()){
                    r++;
                }
            }
        }
        return res;
    }
};
