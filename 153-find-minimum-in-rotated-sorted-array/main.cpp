class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int first = 0, last = n-1, mid;

        while(first < last) {
            if(nums[first] < nums[last]) return nums[first];

            mid = (first + last) / 2;

            // unsorted right
            if(nums[mid] > nums[last]) first = mid+1;

            // sorted right
            else last = mid;
        }

        return nums[first];
    }
};