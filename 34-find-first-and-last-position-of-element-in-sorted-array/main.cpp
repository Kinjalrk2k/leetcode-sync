class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // lower bsearch
        int n = nums.size();
        int first, last, mid, lower, higher;
        vector<int> result;

        first = 0;
        last = n-1;
        lower = n;
        while(first <= last) {
            mid = (first+last)/2;

            if(target == nums[mid]) lower = min(lower, mid);
            if(target > nums[mid]) first = mid+1; 
            else last = mid-1;
            
        }

        first = 0;
        last = n-1;
        higher = -1;
        while(first <= last) {
            mid = (first+last)/2;

            if(target == nums[mid]) higher = max(higher, mid);
            if(target >= nums[mid]) first = mid+1; 
            else last = mid-1;
        }

        if(lower == n) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        } else {
            result.push_back(lower);
            result.push_back(higher);
            return result;
        }
    }
};