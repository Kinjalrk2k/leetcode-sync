class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n+1, 0); // extra 'cause prefix
        pre[0] = 0;  // first is zero
        int c = 0;

        for(int i=1; i<pre.size(); i++) {
            pre[i] = pre[i-1] + nums[i-1];
        }

        // for(auto e: pre) cout<<e<<" ";
        // cout<<endl;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<pre.size(); j++) { 
                int sum = pre[j] - pre[i];
                if(sum == k) {
                    // cout<<i<<" "<<j<<endl;
                    c++;
                }
            }
        }

        return c;
    }
};