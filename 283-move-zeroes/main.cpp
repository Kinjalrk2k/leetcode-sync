class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_point = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (zero_point == -1)
                    zero_point = i;
            } else {
                if (zero_point != -1) {
                    swap(nums[zero_point], nums[i]);
                    zero_point++;
                }
            }
        }
        // cout<<nums[i];
    }
};