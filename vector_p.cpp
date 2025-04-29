#include <iostream>
#include <vector>
#include <unordered_map>  // For storing seen numbers and their indices

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;  
    vector<int> result;

    // Loop through each element in the vector
    for (int i = 0; i < nums.size(); i++) {
        int a = nums[i];
        int complement = target - a; 
       
        if (numMap.find(complement) != numMap.end()) {
            result.push_back(numMap[complement]);  
            result.push_back(i);  
            return result;
        }

        numMap[a] = i;
    }

    return result;  
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    // Output the result
    cout << "Indices of the two numbers are: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
