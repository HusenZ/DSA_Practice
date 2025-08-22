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

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        vector<vector<int>> ans;
        vector<int> current;
        getCombinations(nums, 0, k, current, ans);
        return ans;
    }
};

/*
EXAMPLE TRACE for combine(4, 2) using Solution2:
nums = [1, 2, 3, 4], k = 2

getCombinations(nums, 0, 2, [], ans):
├── i=0: current=[1]
│   └── getCombinations(nums, 1, 2, [1], ans):
│       ├── i=1: current=[1,2] ✓ (size=k, add to ans)
│       ├── i=2: current=[1,3] ✓ (size=k, add to ans)
│       └── i=3: current=[1,4] ✓ (size=k, add to ans)
├── i=1: current=[2]
│   └── getCombinations(nums, 2, 2, [2], ans):
│       ├── i=2: current=[2,3] ✓ (size=k, add to ans)
│       └── i=3: current=[2,4] ✓ (size=k, add to ans)
└── i=2: current=[3]
    └── getCombinations(nums, 3, 2, [3], ans):
        └── i=3: current=[3,4] ✓ (size=k, add to ans)

Final ans: [[1,2], [1,3], [1,4], [2,3], [2,4], [3,4]]

Key Differences from Permutations:
1. Permutations: swap elements, use all positions
2. Combinations: choose/skip elements, only need k positions
3. Permutations: order matters [1,2] ≠ [2,1]
4. Combinations: order doesn't matter, avoid duplicates by using i+1
*/