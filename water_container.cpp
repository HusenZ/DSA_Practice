/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
*/
#include <iostream>
#include <vector>
using namespace std;

int getMaxContainer(vector<int> height){
    int left = 0, right = height.size() - 1;
    int maxArea = 0;

    while (left < right) {
        int currentArea = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, currentArea);

        // Move the pointer pointing to the shorter line
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxArea;
}


int main(){
    cout<<"Hello world"<<endl;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << getMaxContainer(height);

    return 0;
}