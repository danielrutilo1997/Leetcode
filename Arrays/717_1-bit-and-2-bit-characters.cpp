/*
LeetCode 717: 1-bit and 2-bit Characters
Difficulty: Easy
Category: Arrays

Problem Description:
We have two special characters:
- The first character can be represented by one bit 0.
- The second character can be represented by two bits (10 or 11).

Given a binary array bits that ends with 0, return true if the last character
must be a one-bit character.

Example 1:
Input: bits = [1,0,0]
Output: true
Explanation: The only way to decode it is two-bit character (10) + one-bit character (0).

Example 2:
Input: bits = [1,1,1,0]
Output: false
Explanation: The only way to decode it is two-bit character (11) + two-bit character (10).

Constraints:
- 1 <= bits.length <= 1000
- bits[i] is either 0 or 1.
- bits[bits.length - 1] == 0
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
    }
};

// ========== TEST CASES ==========
// Compile and run: g++ -std=c++17 717_1-bit-and-2-bit-characters.cpp -o test && ./test

#ifdef LOCAL_TEST
#include <iostream>
#include <string>

void runTest(vector<int> bits, bool expected, const string& testName) {
    Solution sol;
    bool result = sol.isOneBitCharacter(bits);

    if (result == expected) {
        cout << "✓ PASS: " << testName << endl;
    } else {
        cout << "✗ FAIL: " << testName << endl;
        cout << "  Expected: " << (expected ? "true" : "false") << endl;
        cout << "  Got: " << (result ? "true" : "false") << endl;
    }
}

int main() {
    cout << "Running tests for LeetCode 717: 1-bit and 2-bit Characters\n" << endl;

    // Example test cases from the problem
    runTest({1,0,0}, true, "Example 1: [1,0,0] -> true");
    runTest({1,1,1,0}, false, "Example 2: [1,1,1,0] -> false");

    // Simple edge cases
    runTest({0}, true, "Single zero -> true");
    runTest({1,0}, false, "Just [1,0] -> false");
    runTest({0,0}, true, "Two zeros -> true");

    // More complex cases
    runTest({1,1,0}, true, "Pattern: [1,1] [0] -> true");
    runTest({1,0,1,0}, false, "Pattern: [1,0] [1,0] -> false");
    runTest({0,1,0}, false, "Pattern: [0] [1,0] -> false");
    runTest({0,0,0}, true, "Pattern: [0] [0] [0] -> true");

    // Longer sequences
    runTest({1,1,1,1,0}, true, "Pattern: [1,1] [1,1] [0] -> true");
    runTest({1,0,1,1,0}, true, "Pattern: [1,0] [1,1] [0] -> true");
    runTest({1,1,1,1,1,0}, false, "Pattern: [1,1] [1,1] [1,0] -> false");

    // Mixed patterns
    runTest({0,1,1,1,0}, false, "Pattern: [0] [1,1] [1,0] -> false");
    runTest({0,1,1,0,0}, true, "Pattern: [0] [1,1] [0] [0] -> true");
    runTest({1,0,0,1,0}, false, "Pattern: [1,0] [0] [1,0] -> false");

    cout << "\nAll tests completed!" << endl;

    return 0;
}
#endif
