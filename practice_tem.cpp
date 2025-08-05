#include <iostream>
#include <vector>

using namespace std;

void sortZeros(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            count0++;
        }
        else if (nums[i] == 1) {
            count1++;
        }
        else {
            count2++;
        }
    }
    int indx = 0;
    for (int i = 0; i < count0; i++) {
        nums[indx++] = 0;
    }
    for (int i = 0; i < count1; i++) {
        nums[indx++] = 1;
    }
    for (int i = 0; i < count2; i++) {
        nums[indx++] = 2;
    }

}

int main() {
    vector<int> nums = { 1, 2, 0, 2, 0, 1 };
    sortZeros(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    cout << *(nums.begin());
    return 0;
}