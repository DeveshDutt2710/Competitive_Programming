/*

https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

1721. Swapping Nodes in a Linked List

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
Example 3:

Input: head = [1], k = 1
Output: [1]
Example 4:

Input: head = [1,2], k = 1
Output: [2,1]
Example 5:

Input: head = [1,2,3], k = 2
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        ListNode* newhead = new ListNode();
        while(head != nullptr)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        int n = arr.size();
        int temp = arr[k-1];
        arr[k-1] = arr[n-k];
        arr[n-k] = temp;
        newhead->val = arr[n-1];
        newhead->next = nullptr;
        
        for(int i = n-2;i>=0;i--)
        {
            ListNode* newNode = new ListNode(arr[i], newhead);
            newhead = newNode;
        }
        
        return newhead;
        
    }
};




class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr1 = head, *ptr2 = head, *kth = NULL;
        while (--k)
            ptr1 = ptr1->next;
        
        kth = ptr1;
        ptr1 = ptr1->next;
        
        while (ptr1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        swap(ptr2->val, kth->val);
        return head;
    }
};