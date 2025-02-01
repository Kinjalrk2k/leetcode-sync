class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int t = 0, b = rows - 1, l = 0, r = cols - 1;
        vector<int> result;

        while (t <= b && l <= r) {
            for (int i = l; i <= r; i++)
                result.push_back(matrix[t][i]);
            t++;

            for (int i = t; i <= b; i++)
                result.push_back(matrix[i][r]);
            r--;

            if (t <= b) {
                for (int i = r; i >= l; i--)
                    result.push_back(matrix[b][i]);
                b--;
            }

            if (l <= r) {
                for (int i = b; i >= t; i--)
                    result.push_back(matrix[i][l]);
                l++;
            }
        }

        return result;
    }
};