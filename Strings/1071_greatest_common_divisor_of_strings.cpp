/*
 * LeetCode 1071: Greatest Common Divisor of Strings
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/
 *
 * Problem Description:
 * For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t
 * (i.e., t is concatenated with itself one or more times).
 *
 * Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
 *
 * Example 1:
 * Input: str1 = "ABCABC", str2 = "ABC"
 * Output: "ABC"
 *
 * Example 2:
 * Input: str1 = "ABABAB", str2 = "ABAB"
 * Output: "AB"
 *
 * Example 3:
 * Input: str1 = "LEET", str2 = "CODE"
 * Output: ""
 *
 * Constraints:
 * - 1 <= str1.length, str2.length <= 1000
 * - str1 and str2 consist of English uppercase letters.
 */

#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        // YOUR SOLUTION HERE

    }
};

/*
 * Time Complexity:
 * Space Complexity:
 *
 * Approach:
 *
 */

// Test cases
int main() {
    Solution solution;

    // Test case 1
    std::string result1 = solution.gcdOfStrings("ABCABC", "ABC");
    std::cout << "Test 1 - Expected: ABC, Got: " << result1 << std::endl;

    // Test case 2
    std::string result2 = solution.gcdOfStrings("ABABAB", "ABAB");
    std::cout << "Test 2 - Expected: AB, Got: " << result2 << std::endl;

    // Test case 3
    std::string result3 = solution.gcdOfStrings("LEET", "CODE");
    std::cout << "Test 3 - Expected: (empty), Got: " << result3 << std::endl;

    return 0;
}
