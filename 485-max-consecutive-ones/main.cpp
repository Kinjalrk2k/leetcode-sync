class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_acc = 0;
        int acc = 0;

        for(auto i: nums) {
            if(i == 1) acc++;
            else if(i == 0) {
                max_acc = max(max_acc, acc);
                acc = 0;
            };
        }

        max_acc = max(max_acc, acc);
        return max_acc;
    }
};