class Solution {
public:
    long calcHours(vector<int>& piles, int k) {
        long sum = 0;
        for(auto pile: piles) {
            // sum += long(ceil((double)pile/(double)k));
            if(pile%k == 0) sum += (pile/k);
            else sum += ((pile/k) + 1);
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end()), mid, hours;
        // int left = 1, right = 1000000000, mid, hours;

        while(left < right) {
            mid = left + (right - left) / 2;
            hours = calcHours(piles, mid);
            
            if(hours <= h) right = mid;
            else left = mid + 1;
        }

        return left;
    }
};