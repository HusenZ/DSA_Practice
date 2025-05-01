/*

PROBLEM STATEMENT
4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
             if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
    
            int m = nums1.size();
            int n = nums2.size();
            int left = 0, right = m;
    
            while (left <= right) {
                int i = (left + right) / 2;
                int j = (m + n + 1) / 2 - i;
    
                int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
                int minRight1 = (i == m) ? INT_MAX : nums1[i];
    
                int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
                int minRight2 = (j == n) ? INT_MAX : nums2[j];
    
                if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                    if ((m + n) % 2 == 0)
                        return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                    else
                        return max(maxLeft1, maxLeft2);
                } else if (maxLeft1 > minRight2) {
                    right = i - 1;
                } else {
                    left = i + 1;
                }
            }
    
            return 0.0;
        }
    };