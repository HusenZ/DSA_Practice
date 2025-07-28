#include <iostream>
#include <vector>
#include <numeric>   // for accumulate
#include <algorithm> // for max_element
using namespace std;

bool isValid(vector<int> &nums, int k, int maxSumAllowed)
{
    int subarrays = 1, currSum = 0;
    for (int num : nums)
    {
        if (currSum + num <= maxSumAllowed)
        {
            currSum += num;
        }
        else
        {
            subarrays++;
            currSum = num;
        }
    }
    return subarrays <= k;
}

int splitArray(vector<int> &nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int result = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isValid(nums, k, mid))
        {
            result = mid;   // Possible answer
            high = mid - 1; // Try smaller maxSum
        }
        else
        {
            low = mid + 1; // Need to increase maxSum
        }
    }

    return result;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 5;

    cout << "Minimum largest subarray sum: " << splitArray(nums, k) << endl;

    return 0;
}