class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 1;
        for(int i = 0; i < piles.size(); i++){
            if(r < piles[i]) r = piles[i];
        }
        cout << r << endl;
        int validM;
        while(l <= r){
            int m = l + (r-l)/2;
            int et = 0;
            for(int i = 0; i < piles.size(); i++){
                et += ceil((double)piles[i]/(double)m);
            }
            cout << m << " " << et << endl;
            if(et <= h) {
                r = m-1;
            }
            else l = m+1;

            if(et <= h) validM = m;
        }
        return validM;
    }
};
