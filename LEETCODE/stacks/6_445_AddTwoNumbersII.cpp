/*
https://leetcode.com/problems/add-two-numbers-ii/


445_AddTwoNumbersII

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      	stack<int> stackA;
        stack<int> stackB;
        
		while (l1) {
			stackA.push(l1->val);
			l1 = l1->next;
		}
        
		while (l2) {
			stackB.push(l2->val);
			l2 = l2->next;
		}

		ListNode* Temp = new ListNode(0); 
		
		int carry{}, num1{} ,num2{};

		while (!stackA.empty() || !stackB.empty() || carry) 
        {
			
            if (!stackA.empty()) {
				num1 = stackA.top();
				stackA.pop();
			}
            

			if (!stackB.empty()) {
				num2 = stackB.top();
				stackB.pop();
			}

			int sum = num1 + num2 + carry;
			int value = sum % 10;
			carry = sum / 10;
            
            num1 = 0; 
            num2 = 0;
            
			ListNode* newNode = new ListNode(value);
			newNode->next = Temp->next; 
			Temp->next = newNode;
        }
        return Temp->next;
    }
};