class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1, mid;

        // special
        if(n == 1) return 0;
        
        // corner
        if(nums[0] > nums[1]) return 0;
        if(nums[right] > nums[right-1]) return right;

        while (left <= right) {
            mid = (left + right) / 2;

            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) {
                return mid;
            } else if(nums[mid-1] > nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};