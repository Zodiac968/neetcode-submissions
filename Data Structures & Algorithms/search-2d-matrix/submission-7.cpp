class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();
        int l = 0;
        int r = m*n-1;
        while(l <= r){
            int mm = l + (r-l)/2;
            int k = mm / m;
            int kk = mm % m;
            if(matrix[k][kk] == target) return true;
            else if(matrix[k][kk] < target) l = mm+1;
            else r = mm-1;
        }
        return false;
    }
};
