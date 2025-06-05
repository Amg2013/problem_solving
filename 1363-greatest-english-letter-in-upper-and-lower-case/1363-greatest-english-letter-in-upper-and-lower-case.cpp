#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        bool lower[26] = {false}; // Tracks lowercase letters (a-z)
        bool upper[26] = {false}; // Tracks uppercase letters (A-Z)

        // Mark which letters appear in the string
        for (char c : s) {
            if (islower(c)) lower[c - 'a'] = true;
            else if (isupper(c)) upper[c - 'A'] = true;
        }

        // Find the greatest letter present in both cases
        for (int i = 25; i >= 0; i--) { // Start from Z (index 25) to A (index 0)
            if (lower[i] && upper[i]) {
                return string(1, 'A' + i); // Return uppercase version
            }
        }

        return ""; // Return empty string if no qualifying letter
    }
};
