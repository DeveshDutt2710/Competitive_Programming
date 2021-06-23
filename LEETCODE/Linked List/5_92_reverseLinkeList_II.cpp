
/*

https://leetcode.com/problems/reverse-linked-list-ii/
92. Reverse Linked List II

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

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
    int reverse(int arr[], int start, int end)
    {
        while(start<=end)
        {
            int temp = arr[start-1];
            arr[start-1] = arr[end-1];
            arr[end-1] = temp;
            start++;
            end--;
        }
        return 0;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int arr[500];
        int n=0;
        
        while(head != nullptr)
        {
            n++;
            arr[n-1] = head->val;
            head = head->next;
        }
        reverse(arr, left, right);
        ListNode* finalHead = new ListNode(arr[n-1]);
        
        for(int i = n-2;i>=0;i--)
        {
            ListNode* newnode = new ListNode(arr[i]);
            newnode->next = finalHead;
            finalHead = newnode;
        }
        
        return finalHead;
    }
};