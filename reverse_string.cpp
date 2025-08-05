#include <iostream>
#include <vector>
#include<string>

using namespace std;

void reverseString(vector<char>& s) {
    int start = 0, end = s.size() - 1;
    while (start <= end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

bool isAlphaNum(char ch) {
    if ((ch >= '0' && ch <= '9') ||
        (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
        return true;
    }
    return false;
}

bool isPalindrome(string s) {
    int start = 0, end = s.size() - 1;
    while (start < end) {
        if (!isAlphaNum(s[start])) {
            start++;
            continue;
        }
        if (!isAlphaNum(s[end])) {
            end--;
            continue;
        }
        if (tolower(s[start]) != tolower(s[end])) {
            return false;
        }

        start++;
        end--;
    }
    return true;
}

int main() {
    string name = "amanaplanacanalpanama";
    int last = name.size() - 1;
    cout << isPalindrome(name);
    return 0;
}