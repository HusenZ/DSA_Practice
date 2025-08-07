#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();
        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (target == matrix[row][mid]) {
                return true;
            }
            else if (target > matrix[row][mid]) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int startRow = 0, endRow = m - 1;

        while (startRow <= endRow) {
            int midRow = startRow + (endRow - startRow) / 2;

            if (target >= matrix[midRow][0] &&
                target <= matrix[midRow][n - 1]) {
                // BS on this row
                return searchInRow(matrix, target, midRow);
            }
            else if (target >= matrix[midRow][n - 1]) {
                startRow = midRow + 1;
            }
            else {
                endRow = midRow - 1;
            }
        }
        return false;
    }
};

void spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;

    while (srow <= erow && scol <= ecol) {
        for (int j = scol; j <= n - 1; j++) {
            cout << matrix[srow][j] << " ";
        }
        cout << endl;
        for (int i = srow + 1; i <= erow; i++) {
            cout << matrix[i][ecol] << " ";
        }
        cout << endl;
        for (int j = ecol - 1; j >= scol; j--) {
            cout << matrix[erow][j] << " ";
        }
        cout << endl;
        for (int i = erow - 1; i >= srow + 1; i--) {
            cout << matrix[scol][i] << " ";
        }
        cout << endl;
        srow++;
        scol++;
    }
}

int main() {
    vector<vector<int>> matrix = { {1 ,2, 3}, {4, 5, 6}, {7, 8, 9}, };
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    spiralOrder(matrix);
    return 0;
}