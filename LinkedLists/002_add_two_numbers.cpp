/*
 * LeetCode 2: Add Two Numbers
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/add-two-numbers/
 *
 * Problem Description:
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example 1:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 * Example 2:
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 * Example 3:
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 * Constraints:
 * - The number of nodes in each linked list is in the range [1, 100].
 * - 0 <= Node.val <= 9
 * - It is guaranteed that the list represents a number that does not have leading zeros.
 */

#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // YOUR SOLUTION HERE
        ListNode* l3 = new ListNode(0); // dummy
        
        ListNode* ptr = l1; // point at head of l1
        ListNode* ptr2 = l2; // point at head of l2
        ListNode* ptr3 = l3;
        int sum, carry = 0;
        while(ptr != nullptr || ptr2 != nullptr){
            if(ptr2 == nullptr){
                // solve #8!!!
                sum = carry + ptr->val;
                if(sum > 9){
                    carry = sum / 10;
                    ptr3->next = new ListNode(sum%10);
                    ptr3 = ptr3->next;
                }else{
                    ptr3->next = new ListNode(sum);
                    ptr3 = ptr3->next;
                    carry = 0;
                }
                ptr = ptr->next;                
            }else if (ptr == nullptr){
                /* code */
                sum = carry + ptr2->val;
                if(sum > 9){
                    carry = sum / 10;
                    ptr3->next = new ListNode(sum%10);
                    ptr3 = ptr3->next;
                }else{
                    ptr3->next = new ListNode(sum);
                    ptr3 = ptr3->next;
                    carry = 0;
                }
                ptr2 = ptr2->next;
            }else{
                sum = ptr->val + ptr2->val + carry;
                if(sum > 9){
                    carry = sum / 10; // need to carry to next round
                    ptr3->next = new ListNode(sum%10);
                    ptr3 = ptr3->next;
                }else{
                    ptr3->next = new ListNode(sum);
                    ptr3 = ptr3->next;
                    carry = 0;
                }

                ptr = ptr->next;
                ptr2 = ptr2->next;
            }
                          
        }
        if(carry != 0){
            ptr3->next = new ListNode(carry);
            ptr3 = ptr3->next;
        }

        return l3->next;
    }
};

/*
 * Time Complexity:
 * Space Complexity:
 *
 * Approach:
 *
 */

// Helper function to create a linked list from an array
ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    std::cout << "[";
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) std::cout << ",";
        head = head->next;
    }
    std::cout << "]" << std::endl;
}

// Helper function to free memory
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Test cases
int main() {
    Solution solution;

    // Test case 1: [2,4,3] + [5,6,4] = [7,0,8]
    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});
    ListNode* result1 = solution.addTwoNumbers(l1, l2);
    std::cout << "Test 1 - Expected: [7,0,8], Got: ";
    printList(result1);
    deleteList(l1); deleteList(l2); deleteList(result1);

    // Test case 2: [0] + [0] = [0]
    l1 = createList({0});
    l2 = createList({0});
    ListNode* result2 = solution.addTwoNumbers(l1, l2);
    std::cout << "Test 2 - Expected: [0], Got: ";
    printList(result2);
    deleteList(l1); deleteList(l2); deleteList(result2);

    // Test case 3: [9,9,9,9,9,9,9] + [9,9,9,9] = [8,9,9,9,0,0,0,1]
    l1 = createList({9, 9, 9, 9, 9, 9, 9});
    l2 = createList({9, 9, 9, 9});
    ListNode* result3 = solution.addTwoNumbers(l1, l2);
    std::cout << "Test 3 - Expected: [8,9,9,9,0,0,0,1], Got: ";
    printList(result3);
    deleteList(l1); deleteList(l2); deleteList(result3);

    return 0;
}
/*        while(ptr != nullptr || ptr2 != nullptr){
            if(ptr2 != nullptr){
                sum = ptr->val + ptr2->val + carry;
                if(sum > 9){
                    carry = sum / 10; // need to carry to next round
                    ptr3->next = new ListNode(sum%10);
                    ptr3 = ptr3->next;
                }else{
                    ptr3->next = new ListNode(sum);
                    ptr3 = ptr3->next;
                    carry = 0;
                }

                ptr = ptr->next;
                ptr2 = ptr2->next;
            }else{
                // solve #8!!!
                sum = carry + ptr->val;
                if(sum > 9){
                    carry = sum / 10;
                    ptr3->next = new ListNode(sum%10);
                    ptr3 = ptr3->next;
                }else{
                    ptr3->next = new ListNode(sum);
                    ptr3 = ptr3->next;
                    carry = 0;
                }
                ptr = ptr->next;
                
            }
              
        } */