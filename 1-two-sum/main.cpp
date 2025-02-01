class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hm;
        vector<int> result;

        for(int i=0; i<nums.size(); i++) {
            int res = target - nums[i];
            auto found = hm.find(res);
            if(found != hm.end()) {
                result.push_back(i);
                result.push_back(found->second);
                break;
            } else {
                hm[nums[i]] = i;
            }
        }

        return result;
    }
};