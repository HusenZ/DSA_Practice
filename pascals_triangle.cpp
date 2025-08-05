#include <iostream>
#include <vector>

using namespace std;

vector<int> generateRow(int rowNum) {
    long long ans = 1;
    vector<int> result;
    result.push_back(1);
    for (int i = 1; i < rowNum; i++) {
        ans = ans * (rowNum - i);
        ans = ans / i;
        result.push_back(ans);
    }
    return result;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;

    for (int i = 1; i <= numRows; i++) {
        result.push_back(generateRow(i));
    }
    return result;
}

int main() {

    return 0;
}