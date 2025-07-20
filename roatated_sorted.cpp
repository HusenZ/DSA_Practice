// Rotated Sorted Array - Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

/*
Logic:
- In a rotated sorted array, one half is always sorted.
- Check which half is sorted (left or right).
- If target lies in that half → narrow the search to that half.
- Otherwise → search in the other half.
- Repeat until found or array is exhausted.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int st = 0, end = nums.size() - 1;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            // Left half is sorted
            if (nums[st] <= nums[mid])
            {
                if (nums[st] <= target && target < nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    st = mid + 1;
                }
            }
            // Right half is sorted
            else
            {
                if (nums[mid] < target && target <= nums[end])
                {
                    st = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int index = sol.search(nums, target);
    cout << "Target found at index: " << index << endl;
    return 0;
}
