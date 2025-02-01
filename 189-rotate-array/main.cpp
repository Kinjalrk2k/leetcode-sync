class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        int pivot = len - (k%len);
        reverse(nums.begin(), nums.begin() + pivot);
        reverse(nums.begin() + pivot, nums.end());
        reverse(nums.begin(), nums.end());

        for(auto i: nums) {
            cout<<i<<" ";
        }
    }
};