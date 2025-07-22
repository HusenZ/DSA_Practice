#include <iostream>
#include <vector>

using namespace std;

int findFirst(vector<int> &nums, int target)
{
    int st = 0, end = nums.size() - 1, res = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] == target)
        {
            res = mid;
            end = mid - 1; // keep searching in the left half
        }
        else if (nums[mid] < target)
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return res;
}

int findLast(vector<int> &nums, int target)
{
    int st = 0, end = nums.size() - 1, res = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] == target)
        {
            res = mid;
            st = mid + 1; // keep searching in the right half
        }
        else if (nums[mid] < target)
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return res;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int first = findFirst(nums, target);
    int last = findLast(nums, target);
    return {first, last};
}
int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> result = searchRange(nums, 6);
    for (int val : result)
    {
        cout << val << ", ";
    }

    return 0;
}