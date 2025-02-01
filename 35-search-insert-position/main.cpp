class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int first = 0, last = n-1, mid;

        while(first <= last) {
            mid = (first+last) / 2;

            if(target == nums[mid]) return mid;
            if(target > nums[mid]) first = mid+1;
            else last = mid-1;
        }

        if(target > nums[mid]) return mid+1;
        if(mid == 0) return 0;
        return mid;
    }
};