#include <iostream>
#include <vector>

using namespace std;
// brute force tech
void productExceptSelfBrute(vector<int> &nums)
{
    vector<int> result;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int ans = 1;

        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            ans *= nums[j];
        }

        result.push_back(ans);
    }

    for (int val : result)
        cout << val << " ";
}
vector<int> productExceptSelfS1(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 1);
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        result[i] = prefix[i] * suffix[i];
    }

    return result;
}

/*
 target is to have O(n) time complexity and O(1) space complexity
*/
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 1);

    for (int i = 1; i < n; i++)
    {
        result[i] = result[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suffix *= nums[i + 1];
        result[i] *= suffix;
    }

    return result;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);
    for (int val : result)
        cout << val << " ";
    return 0;
}
