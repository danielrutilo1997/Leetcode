/*
 * LeetCode 1768: Merge Strings Alternately
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/merge-strings-alternately/
 *
 * Problem Description:
 * You are given two strings word1 and word2. Merge the strings by adding letters
 * in alternating order, starting with word1. If a string is longer than the other,
 * append the additional letters onto the end of the merged string.
 *
 * Return the merged string.
 *
 * Example 1:
 * Input: word1 = "abc", word2 = "pqr"
 * Output: "apbqcr"
 * Explanation: The merged string will be merged as so:
 * word1:  a   b   c
 * word2:    p   q   r
 * merged: a p b q c r
 *
 * Example 2:
 * Input: word1 = "ab", word2 = "pqrs"
 * Output: "apbqrs"
 * Explanation: Notice that as word2 is longer, "rs" is appended to the end.
 * word1:  a   b
 * word2:    p   q   r   s
 * merged: a p b q   r   s
 *
 * Example 3:
 * Input: word1 = "abcd", word2 = "pq"
 * Output: "apbqcd"
 * Explanation: Notice that as word1 is longer, "cd" is appended to the end.
 * word1:  a   b   c   d
 * word2:    p   q
 * merged: a p b q c   d
 *
 * Constraints:
 * - 1 <= word1.length, word2.length <= 100
 * - word1 and word2 consist of lowercase English letters.
 */

#include <iostream>
#include <string>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        // YOUR SOLUTION HERE

        int size1, size2; 
        std::string newString; 

        size1 = word1.size();   // store length for comparison
        size2 = word2.size(); 

        if(size1 == size2){
            for(int i = 0; i < size1; i++){

                newString.push_back(word1[i]);
                newString.push_back(word2[i]);

            }
        }else if(size1 > size2){ // word 1 is bigger
            int i = 0;
            while(i < size2){

                newString.push_back(word1[i]);
                newString.push_back(word2[i]);
                i++;                
            }
            while (i < size1){

                newString.push_back(word1[i]);
                i++;

            }
        }else { // word 2 is bigger
            int i = 0;
            while(i < size1){
                newString.push_back(word1[i]);
                newString.push_back(word2[i]);
                i++;
            }
            while(i < size2){
                newString.push_back(word2[i]);
                i++;
            }

        }

        return newString;
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
    std::string result1 = solution.mergeAlternately("abc", "pqr");
    std::cout << "Test 1 - Expected: apbqcr, Got: " << result1 << std::endl;

    // Test case 2
    std::string result2 = solution.mergeAlternately("ab", "pqrs");
    std::cout << "Test 2 - Expected: apbqrs, Got: " << result2 << std::endl;

    // Test case 3
    std::string result3 = solution.mergeAlternately("abcd", "pq");
    std::cout << "Test 3 - Expected: apbqcd, Got: " << result3 << std::endl;

    return 0;
}
