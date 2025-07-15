#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int num : nums)
    {
        ans ^= num; // cancel duplicates
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 1, 4, 2};
    int result = singleNumber(nums);
    cout << result << endl;
    return 0;
}