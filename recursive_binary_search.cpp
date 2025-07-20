#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> nums, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            return binarySearch(nums, mid + 1, end, target);
        }
        else
        {
            return binarySearch(nums, start, mid - 1, target);
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6, 19};
    int result = binarySearch(nums, 0, nums.size() - 1, 6);
    cout << result << " target " << nums[result] << endl;
    return 0;
}

/*
Recursive:
✔ Clean code
❌ O(log n) space (call stack)
❌ Stack overflow risk

Iterative:
✔ O(1) space
✔ More efficient
✔ Production-ready
*/