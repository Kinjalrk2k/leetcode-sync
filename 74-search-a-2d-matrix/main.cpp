class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int n = rows*cols;
        int left = 0, right = n-1, mid, r, c;

        while(left <= right) {
            mid = (left+right) / 2;
            r = mid / cols;
            c = mid % cols;

            // cout<<matrix[r][c]<<" ";
            if(matrix[r][c] == target) {
                return true;
            } else if(matrix[r][c] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        return false;
    }
};