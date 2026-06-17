class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();
        int l = 0;
        int r = m*n - 1;
        while(l <= r){
            int mid = l + (r-l)/2;
            int z = mid/m;
            int i = mid - z*m;
            if(matrix[z][i] == target){
                return true;
            }
            else if(matrix[z][i] < target){
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return false;
    }
};
