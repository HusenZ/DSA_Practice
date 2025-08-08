#include <iostream>
#include <vector>

using namespace std;

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();
    vector<bool> used(n, false);  // Track which baskets are used
    int unplacedCount = 0;        // Count unplaced fruits

    // Try to place each fruit
    for (int fruit : fruits) {
        bool placed = false;

        // Find the leftmost available basket that can fit this fruit
        for (int i = 0; i < n; i++) {
            if (!used[i] && baskets[i] >= fruit) {
                used[i] = true;  // Mark basket as used
                placed = true;
                break;           // Move to next fruit
            }
        }

        if (!placed) {
            unplacedCount++;
        }
    }

    return unplacedCount;
}

int main() {

    return 0;
}