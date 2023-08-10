#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int getIndex2(string &s, vector<string> &v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == s) {
            return i;
        }
    }
    return -1;
}

int getIndex(char &c, const vector<char> &v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == c) {
            return i;
        }
    }
    return -1;
}

int main() {
    const vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                   'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                   'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                   'Y', 'Z', '_', ',', '.', '?'};

    vector<string> morse = {".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                            "--.",  "....", "..",   ".---", "-.-",  ".-..",
                            "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                            "...",  "-",    "..-",  "...-", ".--",  "-..-",
                            "-.--", "--..", "..--", ".-.-", "---.", "----"};

    string s;
    while (getline(cin, s)) {
        string morseCode;
        vector<int> lengths;
        string decoded;

        for (auto c : s) {
            int index = getIndex(c, alphabet);
            string item = morse[index];
            morseCode += item;
            lengths.push_back(item.length());
        }

        reverse(lengths.begin(), lengths.end());

        int n = 0;
        for (int i = 0; i < lengths.size(); i++) {
            string m = morseCode.substr(n, lengths[i]);
            decoded += alphabet[getIndex2(m, morse)];
            n += lengths[i];
        }

        cout << decoded << endl;
    }
    return 0;
}

