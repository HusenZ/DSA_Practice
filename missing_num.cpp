#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int> nums)
{
    int n = nums.size();
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int num : nums)
    {
        sum += num;
    }
    return total - sum;
}

int main()
{

    return 0;
}