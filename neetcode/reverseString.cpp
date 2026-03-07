#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 //  Given the beginning of a singly linked list head, reverse the list, and return the new beginning of the list.
 // Example 1:
 // Input: head = [0,1,2,3]
 // Output: [3,2,1,0]

 // Example 2:
 // Input: head = []
 // Output: []

 // Constraints:
 // 0 <= The length of the list <= 1000.
 // -1000 <= Node.val <= 1000
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  /**
   * Reverses a singly linked list.
   *
   * Given the beginning of a singly linked list `head`, reverses the list and returns the new beginning of the list.
   *
   * Time complexity: O(n)
   * Space complexity: O(1)
   *
   * @param head the beginning of the singly linked list to reverse
   * @return the new beginning of the reversed list
   */
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    while (curr != nullptr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};

