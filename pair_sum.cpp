#include <iostream>
#include <vector>

using namespace std;

vector<int> pairSum(vector<int> nums, int target)
{
    vector<int> result;
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        if (nums[low] + nums[high] == target)
        {
            result.push_back(low);
            result.push_back(high);
            return result;
        }
        else if (nums[low] + nums[high] > target)
        {
            high--;
        }
        else if (nums[low] + nums[high] < target)
        {
            low++;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {2, 3, 4, 7, 11, 15};
    vector<int> result = pairSum(nums, 26);
    for (int val : result)
    {
        cout << val << " ,";
    }
    return 0;
}