class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();
        int l = 0;
        int r = m-1;
        int z = 0;
        while(l <= r && z < n){
            if(matrix[z][m-1] < target){ cout << "less" << endl; z++; continue; }
            int mid = l + (r-l)/2;
            if(matrix[z][mid] == target){
                return true;
            }
            else if(matrix[z][mid] < target){
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return false;
    }
};
