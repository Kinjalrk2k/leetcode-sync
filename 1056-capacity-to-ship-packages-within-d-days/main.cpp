class Solution {
public:
    bool condition(vector<int>& weights, int max_weight, int max_days) {
        int days = 1;
        int sub_total = 0;
        for(auto e: weights) {
            sub_total += e;
            if(sub_total > max_weight) {
                days++;
                sub_total = e;
            }
        }

        return days <= max_days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int size = weights.size();
        int left = *max_element(weights.begin(), weights.end());
        int right = 0;
        for(auto e: weights) right += e;
        int mid;

        while(left < right) {
            mid = (left + right) / 2;
            if(condition(weights, mid, days)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }

        return left;
    }
};