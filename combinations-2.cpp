#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void getCombinations(vector<int>& nums, int idx, int k,
        vector<int>& current, vector<vector<int>>& ans) {
        // Base case: we've selected k elements
        if (current.size() == k) {
            ans.push_back(current);
            return;
        }

        // Base case: not enough elements left
        if (idx == nums.size()) {
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            // Choose: add current element to combination
            current.push_back(nums[i]);

            // Recurse: move to next position, looking for remaining elements
            getCombinations(nums, i + 1, k, current, ans);

            // Backtrack: remove the element we just added
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    }
};
