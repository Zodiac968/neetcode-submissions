class Solution {
public:
    int countSubstrings(string s) {
        string padded = "#";
        for(int i = 0; i < s.size(); i++){
            padded += s[i];
            padded += '#';
        }
        cout << padded << endl;
        int count = 0;
        for(int i = 0; i < padded.size(); i++){
            int l = i;
            int r = i;
            while(l >= 0 && r < padded.size()){
                if(padded[l] == padded[r]) {
                    if(padded[l] != '#') 
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
