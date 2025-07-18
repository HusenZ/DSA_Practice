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

// n/3 boore moores voting
vector<int> majorityElementN3(vector<int> &nums)
{
    int count1 = 0, count2 = 0;
    int ans1 = 0, ans2 = 1;
    vector<int> result;

    for (int num : nums)
    {
        if (num == ans1)
        {
            count1++;
        }
        else if (num == ans2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            ans1 = num;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            ans2 = num;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for (int num : nums)
    {
        if (num == ans1)
            count1++;
        else if (num == ans2)
            count2++;
    }

    int n = nums.size();
    if (count1 > n / 3)
        result.push_back(ans1);
    if (count2 > n / 3)
        result.push_back(ans2);

    return result;
}

int main()
{
    vector<int> nums = {3, 2, 3};
    vector<int> result = majorityElementN3(nums);
    for (int num : result)
    {
        cout << num << " ,";
    }
    return 0;
}