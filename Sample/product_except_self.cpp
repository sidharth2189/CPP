/*
	PRODUCT OF ARRAY EXCEPT SELF
	
	Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
	Example:
	Input:  [1,2,3,4]
	Output: [24,12,8,6]
	Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.
	Note: Please solve it without division and in O(n).
	Follow up:
	Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left, right, result;
        
        int product = 1;
        for (int count = 0; count < nums.size(); count++)
        {
            if (count == 0) {product = 1;}
            else {product = product * nums[count-1];}
            left.push_back(product);
        }
        
        product = 1;
        for (int count = nums.size() - 1; count >= 0; count--)
        {
            if (count == nums.size() - 1) {product = 1;}
            else {product = product * nums[count+1];}
            right.push_back(product);
        }

        for (int count = 0; count < nums.size(); count++)
        {
            product = left[count] * right[nums.size() - count - 1];
            result.push_back(product);
        }
        return result;
    }
};