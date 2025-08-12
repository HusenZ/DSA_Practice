#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateArray(vector<int>& nums) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        swap(nums[start], nums[end]);
        start++; end--;
    }

}

int missingNumber(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i + 1) {
            return i;
        }
    }
    return -1;
}

int secondLargets(vector<int> nums) {
    fint first = INT_MIN, second = INT_MIN;
    for (int num : nums) {
        if (num > first) {
            second = first;
            first = num;
        }
        else if (num > second && num < first) {
            second = num;
        }
    }
    return (second == INT_MIN) ? -1 : second;
}

int main() {
    vector<int> nums = { 10, 20, 4, 45, 99 };
    cout << secondLargets(nums) << endl;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    cout << (1 << 1) << endl;
    return 0;
}