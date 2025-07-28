#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
bool countSplits(vector<int> &nums, int k, int maxSumAllowed)
{
    int split = 1, currSum = 0;
    for (int num : nums)
    {
        if (currSum + num <= maxSumAllowed)
        {
            currSum += num;
        }
        else
        {
            split++;
            currSum = num;
        }
    }
    return split <= k;
}

int splitArray(vector<int> &nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());   // Minimum possible max subarray sum
    int high = accumulate(nums.begin(), nums.end(), 0); // Maximum possible max subarray sum

    int result = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (countSplits(nums, k, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
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