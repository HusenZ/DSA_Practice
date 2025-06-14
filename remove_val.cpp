/*
===========================
📌 LeetCode-Style Problem
===========================

🎯 Problem: Remove Element (In-Place)
--------------------------------------
Given an integer array `nums` and an integer `val`, remove **all occurrences** of `val` in-place.
The order of the elements **may be changed**.
Then return the number of elements in `nums` which are **not equal** to `val`.

🧠 Custom Judge:
---------------
- After calling your function, the first `k` elements of `nums` should be the elements not equal to `val`.
- The remaining elements can be anything.
- Return `k` — the count of elements not equal to `val`.

🧪 Example:
----------
Input: nums = [3,2,2,3], val = 3
Output: 2
Modified nums = [2,2,_,_]

📌 Note:
- You do not need to preserve the order.
- You must do it in-place (no extra array).

🧠 Approach:
------------
- Use two pointers: one from start `i`, one from end `n`
- If nums[i] == val → replace it with last valid value `nums[n - 1]`, shrink `n--`
- Else move to next `i++`
- This way, every value is checked exactly once, and removed in O(1)

====================================
✅ Solution: In-Place O(n) Approach
====================================
*/

#include <iostream>
#include <vector>
using namespace std;

int remove_val(int val, vector<int> &nums)
{
    int i = 0;
    int n = nums.size();

    while (i < n)
    {
        if (nums[i] == val)
        {
            nums[i] = nums[n - 1]; // Move last valid element forward
            n--;                   // Shrink the size boundary
        }
        else
        {
            i++; // Only move if current is not val
        }
    }

    return n; // New size (count of elements not equal to val)
}

int main()
{
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int k = remove_val(val, nums);

    cout << "New length: " << k << endl;
    cout << "Modified nums: ";
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
📌 Output:
New length: 2
Modified nums: 2 2

✅ Time Complexity: O(n)
✅ Space Complexity: O(1)
*/
