#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int maxSumSubArray(vector<int> nums, int k)
{
    if (nums.size() == 0)
        return 0;
    int maxSum = 0, windowSum = 0;

    for (int i = 0; i < k; i++)
    {
        windowSum += nums[i];
    }
    maxSum = windowSum;

    for (int i = k; i < nums.size(); i++)
    {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> maxSum = maxSlidingWindow(nums, 3);
    cout << " Result vecotr" << endl;
    for (int value : maxSum)
    {
        cout << value << endl;
    }
    return 0;
}