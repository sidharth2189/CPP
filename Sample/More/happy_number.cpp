/*

HAPPY NUMBER

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

class Solution {
public:
    bool isHappy(int num) {
        int a, new_num, count = 0;
        if (num == 1)
        {
            return true;
        }
        else if (num < 0)
        {
            return false;
        }
        else
        {
            while (num!=0)
            {
                new_num = 0;
                while (num != 0)
                {
                    while ((num%10) == 0)
                    {
                        num = num/10;
                    }
                    a = num%10;
                    new_num = new_num + a*a;
                    num = num - a;
                }
                num = new_num;
                if (num == 1 || num ==7)
                {
                    return true;
                }
                else if (num < 10 && num != 1 && num != 7 )
                {
                    return false;
                }
                
            }
            return false;
        }
    }
};