#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    stringstream ss(s);
    vector<string> words;
    string word;

    while (ss >> word) {
        words.push_back(word);
    }
    string lstwrd = words[words.size() - 1];
    return lstwrd.length();
}

int main() {
    string sentence = " This is the temp ";
    stringstream ss(sentence);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    for (string w : words) {
        cout << w << " ";

    }
    cout << endl;
    cout << words.size();
    return 0;
}