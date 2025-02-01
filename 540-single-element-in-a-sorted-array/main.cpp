class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n - 1;

        // special case
        if(n == 1) return nums[0];

        // corner cases
        if(nums[0] != nums[1]) return nums[0];
        if(nums[right] != nums[right-1]) return nums[right];

        left++;
        right--;

        while (left <= right) {
            int mid = (right + left) / 2;
            if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid-1]) return nums[mid];

            if (mid % 2 != 0) {
                // odd
                if (nums[mid] == nums[mid - 1]) {
                    cout << "right";
                    left = mid + 1;
                } else {
                    cout << "left";
                    right = mid - 1;
                }
            } else {
                // even
                if (nums[mid] == nums[mid + 1]) {
                    cout << "right";
                    left = mid+1;
                } else {
                    cout << "left";
                    right = mid - 1;
                }
            }

            cout << " l" << left << " r" << right<<" " << mid << " " << nums[mid];
            cout << endl;
        }

        return -1;
    }
};