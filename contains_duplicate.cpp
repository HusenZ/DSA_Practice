#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    int compareValue = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {

            if (nums[j] == nums[i])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << containsDuplicate(nums) << endl;
    return 0;
}