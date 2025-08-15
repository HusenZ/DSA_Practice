#include <iostream>
#include <vector>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int l = 0, r = 0, sum = 0, maxlen = 0;

    while (r <= nums.size()) {
        sum += nums[r];
        while (sum > k) {
            sum -= nums[l];
            l++;
        }
        maxlen = max(maxlen, r - l + 1);
        r++;
    }

    return maxlen;
}


int main() {
    vector<int> nums = { 1,1,1 };
    cout << subarraySum(nums, 2);
    return 0;
}