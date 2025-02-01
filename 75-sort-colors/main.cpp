class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto start = nums.begin();
        auto end = nums.end() - 1;

        for(auto it = nums.begin(); it <= end; ) {
            if(*it == 0) {
                iter_swap(it, start);
                start++;
                it++;
            } else if(*it == 1) {
                it++;
            } else {
                iter_swap(it, end);
                end--;
            }
        }
    }
};