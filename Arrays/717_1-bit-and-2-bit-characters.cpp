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
