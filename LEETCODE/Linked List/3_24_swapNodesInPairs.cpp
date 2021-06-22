/*
https://leetcode.com/problems/swap-nodes-in-pairs/

24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100


*/


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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp;
        temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        
        return temp;
    }
};





class Solution {
public:
    ListNode* swapPairs(ListNode *head) {
        ListNode *originalHead = head && head->next ? head->next : head, *tmp, *nextHead;
        while (head && head->next) {
            // storing the current value of the node following head
            tmp = head->next;
            // storing the head of the next loop
            nextHead = head->next->next;
            // updating head->next
            head->next = head->next->next && head->next->next->next ? head->next->next->next : head->next->next;
            // switching head and its previous next position
            tmp->next = head;
            // setting the head of the next loop
            head = nextHead;
        }
        return originalHead;
    }
};