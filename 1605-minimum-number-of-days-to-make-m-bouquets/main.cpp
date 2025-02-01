class Solution {
public:
    bool condition(vector<int> &bloomDay, int m, int k, int day) {
        int final_count = 0;
        int temp_count = 0;
        for(auto e: bloomDay) {
            if(e <= day) {
                temp_count++;
                if(temp_count == k) {
                    final_count++;
                    temp_count = 0;
                }
            } else {
                temp_count = 0;
            }
        }

        cout<<final_count;

        return final_count >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // vector<int> v = {1, 0, 1, 1, 0};
        // condition(v, m, 1);

        int size = bloomDay.size();
        if(size < static_cast<long>(m)*k) return -1;

        auto minmax = minmax_element(bloomDay.begin(), bloomDay.end());
        int left = *minmax.first;
        int right = *minmax.second;
        int mid;

        while(left < right) {
            mid = (left+right) / 2;
            if(condition(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};