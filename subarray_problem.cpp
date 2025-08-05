#include <iostream>
#include <vector>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int currSum = 0, count = 0;
    for (int i = 0; i < nums.size(); i++) {
        currSum += nums[i];
        if (currSum == k) {
            count++;
            currSum = 0;
        }
    }
    return count;
}

int main() {
    vector<int> nums = { 1,1,1 };
    cout << subarraySum(nums, 2);
    return 0;
}