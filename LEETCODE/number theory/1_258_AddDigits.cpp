/*

https://leetcode.com/problems/add-digits/
258_AddDigits

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0
 

Constraints:

0 <= num <= 231 - 1
*/

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        if(num/10 == 0)
        {
            return num;
        }
        else
        {
            while(num)
            {
                int digit = num%10;
                num = num/10;
                sum += digit;
            }
        }
        return addDigits(sum);
        
    }
};




class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
        {
            return num;
        }
        if(num%9 == 0)
        {
            return 9;
        }
        
        return num%9;
    }
};