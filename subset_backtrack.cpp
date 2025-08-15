#include <iostream>
#include <vector>

using namespace std;

void printSubsets(vector<int>& arr, vector<int>& res, int i) {
    if (i == arr.size()) {
        for (int val : res) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }
    // include
    res.push_back(arr[i]);
    printSubsets(arr, res, i + 1);

    // exclude
    res.pop_back(); // back track
    printSubsets(arr, res, i + 1);
}

int main() {
    vector<int> arr = { 1, 2, 3 };
    vector<int> ans; // store the subsets

    printSubsets(arr, ans, 0);
    return 0;
}

/// leetcode question 78
class Solution {
public:

    void getSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
        if (i == nums.size()) {
            allSubsets.push_back({ ans });
            return;
        }

        ans.push_back(nums[i]);
        getSubsets(nums, ans, i + 1, allSubsets);

        ans.pop_back();
        getSubsets(nums, ans, i + 1, allSubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;

        getSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};