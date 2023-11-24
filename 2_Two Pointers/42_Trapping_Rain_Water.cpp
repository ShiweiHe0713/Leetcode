class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0 || height.size() > 20000) return 0;
        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int result = 0;
        int min_ = 0;

        while(l < r) {
            if(leftMax < rightMax) {
                if(leftMax - height[l] > 0) {
                    result += leftMax - height[l];
                } else {
                    result += 0;
                }
                l++;
                leftMax = max(leftMax, height[l]);
            }
            else {  // leftMax > rightMax
                if(height[r] < rightMax) {
                    result += rightMax - height[r];
                } else {
                    result += 0;
                }
                r--;
                rightMax = max(rightMax, height[r]);
            }
        }
        return result;
    }
};



