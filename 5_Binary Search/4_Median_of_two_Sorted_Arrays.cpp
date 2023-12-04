class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    /*
        1. Define the needed vairables: len1, len2, shorter_one_len1, the l, r of short_1, total size
        2. 开始循环，循环条件是if(true)
        3. 开始定义每次循环需要更新的变量：mid1, mid2, l1, r1, l2, r2
        4. 开始判断partition是否正确
            4.1 如果两个数组中左边最右的两个元素l1,l2均小于右边最左的两个元素r1, r2, 则正确
            4.2 如果l1 > r2, l1 左移至mid1左
            4.3 如果l2 > r1, l2 左移至mid2左
        5. 开始判断数组是否为奇数或者偶数
            5.1 如果数组为奇数，返回两个右边最左元素中小的那个
            5.2 如果数组为偶数，返回两个左边最右元素和两个右边最左元素之和的平均值
        时间复杂度：O(logn)? 只遍历了总长度的一半？不确定
        空间复杂度：O(0)，没有定义额外数据结构
    */
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int len1 = nums1.size(), len2 = nums2.size();
        int total = len1 + len2;
        int l = 0, r = len1;   // only used for nums1

        while(true) {
            int mid1 = l + (r - l) / 2;
            int mid2 = (total + 1) / 2 - mid1;  // why add 1

            // l1,l2,r1,r2表示的是值，不是index
            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < len1) ? nums1[mid1] : INT_MAX;
            int r2 = (mid2 < len2) ? nums2[mid2] : INT_MAX;

            // Partition is correct
            if(l1 <= r2 && l2 <= r1) {
                if(total % 2) { // odd
                    return max(l1, l2);
                } else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                break;
            } else if(l1 > r2) {
                r = mid1 - 1;
            } else { // l2 > r1
                l = mid1 + 1;
            }
        }
        return 0.0;
    }
};
