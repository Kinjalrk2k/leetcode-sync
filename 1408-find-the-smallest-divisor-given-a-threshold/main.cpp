class Solution {
public:
    bool condition(vector<int>& nums, int threshold, int num) {
        int total = 0;
        // cout<<num<<" = ";
        for(auto e: nums) {
            // cout<<ceil(float(e)/num)<<" + ";
            total += ceil(float(e)/num);
        }

        // cout<<" ~> "<<total<<endl;
        return total <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int mid;

        while (left < right) {
            mid = (left+right) / 2;
            if(condition(nums, threshold, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};