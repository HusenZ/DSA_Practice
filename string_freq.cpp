#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Method 1: Using Array (for lowercase letters only)
vector<int> getFrequencyArray(string s) {
    vector<int> freq(26, 0);  // a-z mapping
    for (char c : s) {
        freq[c - 'a']++;  // maps 'a' -> 0, 'b' -> 1,..... 'z' -> 25
    }
    return freq;
}

int main() {
    vector<int> freq1 = getFrequencyArray("husen");
    vector<int> freq2 = getFrequencyArray("uhsne");
    for (int num : freq1) {
        cout << num << " ";
    }
    cout << endl;
    cout << "freq 2" << endl;
    if (freq1 == freq2) {
        cout << "valid anagram" << endl;
    }
    for (int num : freq2) {
        cout << num << " ";
    }
    return 0;
}