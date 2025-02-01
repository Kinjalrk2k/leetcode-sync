class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int first = 0, last = n-1;

        while(first <= last) {
            int mid = (first+last)/2;
            if(target == nums[mid]) return mid;

            if(target > nums[mid]) {
                first = mid+1;
            } else {
                last = mid-1;
            }
        }

        return -1;
    }
};