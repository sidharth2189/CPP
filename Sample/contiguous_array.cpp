/*

    CONTIGUOUS ARRAY

    Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

    Example 1:
    Input: [0,1]
    Output: 2
    Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
    Example 2:
    Input: [0,1,0]
    Output: 2
    Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
    Note: The length of the given binary array will not exceed 50,000.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


/* 

// Program to find the length of longest sequence of alternating binary values in a given vector of binary values

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0;
        if (nums.size() > 1)
        {
            int count = 0, max = 0, temp;
            vector<int> maximum;
            vector<int>::iterator it = nums.begin();
            temp = *it;
            while (it != nums.end())
            {
                if (temp != *it) 
                {
                    count++;
                    if (max < count && count%2 != 0) {max = count;}
                }
                
                else 
                {
                    max = 0;
                    count = 0;
                }
                maximum.push_back(max);
                temp = *it;
                it++;
            }
            result = *max_element(maximum.begin(), maximum.end()) + 1;
        }
        return result;
    }
};

int main()
{
    vector<int> p{0,0,0,1,0,1,1,0,1};
    Solution sol;
    int result = sol.findMaxLength(p);
    cout << result << endl;
}

*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0;
        if (nums.size() > 1)
        {
            if (nums.size() == 2)
            {
                vector<int> num1{0,1};
                vector<int> num2{1,0};
                if (nums == num1 || nums == num2) {return 2;}
                else {return result;}
            }
            vector<int> max;
            int count_zeros, count_ones, flag = 0;
            for (int count_out = 0; count_out < nums.size(); count_out++)
            {
                count_zeros = 0, count_ones = 0;
                flag = 0;
                for (int count_in = count_out; count_in < nums.size() && flag == 0; count_in++)
                {
                    if (nums[count_in] == 1) {count_ones++;}
                    else {count_zeros++;}
                    if (abs(count_zeros - count_ones) > (nums.size() - count_ones - count_zeros -1))
                    {
                        max.push_back(2 * min(count_zeros, count_ones));
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    max.push_back(2 * min(count_zeros, count_ones));
                }
            }
            if (max.size() > 1) {result = *max_element(max.begin(), max.end());}
            else if (max.size() == 1) {result = *max.begin();}
            else {result = 0;}
        }
        return result;
    }
};