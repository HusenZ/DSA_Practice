#include <iostream>
#include <vector>

using namespace std;

// moores voting algo
int majorityElement(vector<int> &nums)
{
    int count = 0;
    int ans = 0;
    for (int num : nums)
    {
        if (count == 0)
        {
            ans = num;
        }
        if (num == ans)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return ans;
}

int majorityElementBrute(vector<int> nums)
{
    int i, j, count = 0;
    for (i = 0; i < nums.size(); i++)
    {
        for (j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
            if (count >= (nums.size()) / 2)
            {
                return nums[i];
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 2, 2};
    cout << majorityElementBrute(nums) << endl;
    return 0;
}