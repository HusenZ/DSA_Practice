#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int threeSumClost(vector<int> nums, int target)
{
    sort(nums.begin(), nums.end());

    int result = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size(); i++)
    {
        // Skip duplicate 'i'
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            // get the absolute value
            if (abs(sum - target) < abs(result - target))
            {
                result = sum;
            }

            // Move pointers
            if (sum < target)
            {
                left++; // Need a bigger sum
            }
            else
            {
                right--; // Need a smaller sum
            }
        }
    }
    return result;
}

int main()
{
    /* code */
    vector<int> nums = {-1, 2, 1, -4};
    cout << threeSumClost(nums, 1) << endl;
    return 0;
}
