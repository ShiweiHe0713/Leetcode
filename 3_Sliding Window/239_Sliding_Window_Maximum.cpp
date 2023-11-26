class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        int l = 0, r = 0;

        while(r < nums.size()) {
            while(!dq.empty() && nums[r] > nums[dq.back()]) {
                dq.pop_back();
            }
            // make sure only smallers are push to the back
            dq.push_back(r);

            if(l > dq.front()) {
                dq.pop_front();
            }
            
            // r surpass the first window end index
            if(r + 1 >= k) {     // should include r == k - 1
                result.push_back(nums[dq.front()]);
                l++;
            }
            // if use r + 1 > k, l will incremen [k, n] = n - k + 1 times
            // but l should increment [k-1, n] = n - k + 2 times, the first window got ignored
            r++;
        }

        return result;
    }
};
