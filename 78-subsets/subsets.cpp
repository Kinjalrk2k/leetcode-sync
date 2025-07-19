class Solution {
public:
    vector<vector<int>> res;

    void bt(vector<int> t, vector<int> nums, int idx) {
        res.push_back(t);
        for(int i=idx; i<nums.size(); i++) {
            t.push_back(nums[i]);
            bt(t, nums, i+1);
            t.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> gen;
        bt(gen, nums, 0);
        return res;
    }
};