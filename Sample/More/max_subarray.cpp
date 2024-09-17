/*
MAXIMUM SUB-ARRAY

Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and 
conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = std::accumulate(nums.begin(), nums.end(), 0);
        int current_sum = 0;
        for (auto x: nums)
        {
            current_sum = current_sum + x;
            
            if (max_sum < current_sum) {max_sum = current_sum;}
            if (current_sum < 0) {current_sum = 0;}
        }
        return max_sum;   
    }
};