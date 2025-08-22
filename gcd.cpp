// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>

// using namespace std;

// int gcdHelper(int a, int b) {
//     return b == 0 ? a : gcdHelper(b, a % b);
// }

// void backtrack(vector<int>& nums, int start, int currentGCD, set<pair<int, int>>& seen, long long& sum) {
//     if (start > 0) {  // non-empty subset
//         if (seen.insert({ start, currentGCD }).second) {  // only add if unique
//             sum += currentGCD;
//         }
//     }
//     for (int i = start; i < nums.size(); i++) {
//         if (i > start && nums[i] == nums[i - 1]) continue; // skip duplicates
//         int newGCD = (currentGCD == 0) ? nums[i] : gcdHelper(currentGCD, nums[i]);
//         backtrack(nums, i + 1, newGCD, seen, sum);
//     }
// }

// int sumOfGCDs(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     nums.erase(unique(nums.begin(), nums.end()), nums.end()); // remove duplicates
//     long long sum = 0;
//     backtrack(nums, 0, 0, sum);
//     return (int)sum;
// }


// int main() {
//     vector<int> nums = { 3,2,3,4 };
//     cout << sumOfGCDs(nums) << endl;
//     return 0;
// }
