#include <iostream>
#include <string>

using namespace std;

void printPermutations(string str, int idx) {
    if (idx == str.length()) {
        cout << str << endl;
        return;
    }
    for (int i = idx; i < str.length(); i++) {
        swap(str[idx], str[i]);
        printPermutations(str, idx + 1);
        swap(str[idx], str[i]);
    }

}

int main() {
    printPermutations("abc", 0);
    return 0;
}