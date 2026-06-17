class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = -1;
        for(int i = 0; i < piles.size(); i++){
            if(r < piles[i]) r = piles[i];
        }
        int l = 1;
        int k = 0;
        while(l <= r){
            int m = (r+l)/2;
            cout << l << " " << r << " " << m << endl;
            int hours = h;
            for(int i = 0; i < piles.size(); i++){
                hours -= ceil((double)piles[i] / (double)m);
            } 
            if(hours < 0) l = m+1;
            else{
                k = m;
                r = m-1;
            }
        }
        return k;
    }
};
