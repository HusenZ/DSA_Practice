#include <iostream>
#include <vector>

using namespace std;

void linearSearch(int matrix[][3], int rows, int cols, int key) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == key) {
                cout << "Element found at " << i << " " << j << endl;
                return;
            }
        }
    }
    cout << "element not found" << endl;
}

// max row sum

int maxRowSum(int matrix[][3], int rows, int cols) {
    int maxSum = 0;
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
            cout << " Row " << i << " : " << rowSum << endl;
        }
        maxSum = max(maxSum, rowSum);
        cout << "max sum: " << maxSum << endl;
    }
    return maxSum;
}

//daigonal sum
int daigonalSum(int matrix[][3], int rows) {
    int sum = 0;
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < rows; j++) {
    //         if (i == j) {
    //             sum += matrix[i][j];
    //         }
    //         else if (j == rows - i - 1) {
    //             sum += matrix[i][j];
    //         }
    //     }
    // }

    /// primary daigonal : j = i
    /// secondary daigonal : n-i-1
    for (int i = 0; i < rows; i++) {
        sum += matrix[i][i];

        if (i != rows - i - 1) {
            sum += matrix[i][rows - i - 1];
        }
    }

    return sum;
}

int main() {
    int matric[3][3] = { {1 ,2, 3}, {4, 5, 6}, {7, 8, 9}, };
    int rows = 3;
    int cols = 3;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matric[i][j] << " ";
        }
        cout << endl;
    }
    linearSearch(matric, rows, cols, 9);
    cout << maxRowSum(matric, rows, cols) << endl;
    cout << daigonalSum(matric, rows) << endl;
    /*---------------------------[2D vector]--------------------------*/
    vector<vector<int>> mat = { {1 ,2, 3}, {4, 5, 6, 10, 11}, {7, 8, 9}, };
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    /*
        rows => mat.size();
        cols => mat[i].size()
    */
    return 0;
}