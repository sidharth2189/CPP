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
        vector<int> result;
        int product = 1;
        for (vector<int>::iterator it = nums.begin(); it < nums.end(); it++)
        {
            if (it > nums.begin() && it < nums.end()-1) 
            {
                product = accumulate(nums.begin(), it, 1, multiplies<int>());
                product = accumulate(it+1, nums.end(), product, multiplies<int>());
                result.push_back(product);
            }
            else if (it == nums.begin())
            {
                product = accumulate(nums.begin()+1, nums.end(), 1, multiplies<int>());
                result.push_back(product);
            }
            else
            {
                product = accumulate(nums.begin(), nums.end()-1, 1, multiplies<int>());
                result.push_back(product);
            }
            
        }
        return result;
    }
};