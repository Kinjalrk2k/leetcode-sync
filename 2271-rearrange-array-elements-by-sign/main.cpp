class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos_vec, neg_vec, result;
        int result_len = nums.size() / 2;

        for(auto e : nums) {
            if(e < 0) neg_vec.push_back(e);
            else pos_vec.push_back(e);
        }

        for(int i=0; i<result_len; i++) {
            result.push_back(pos_vec[i]);
            result.push_back(neg_vec[i]);
        }

        return result;
    }
};