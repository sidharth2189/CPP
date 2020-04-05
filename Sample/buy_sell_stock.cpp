/*
=== Best Time to Buy and Sell Stock II ===

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions 
as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell 
the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
        int start, next, sum = 0, x = 0;
        
        if (prices.empty() == false)
        {
            start = prices[0];
            if (is_sorted(prices.begin(), prices.end()))
            {
                sum = prices.back() - prices.front();
                return sum;
            }
            
            while (x < prices.size())
            {            
                while (prices[x] <= start)
                {
                    start = prices[x];
                    x++;
                    if (x == prices.size()-1)
                    {
                        next = prices[x];
                        if (next > start)
                        {
                            sum = sum + next - start;
                        }/*
                        if (next <= start)
                        {
                            sum = sum + 0;
                        }
                        else
                        {
                            sum = sum + next - start;
                        }*/
                        return sum;
                    }
                    next = prices[x];
                }
                
                while (prices[x] >= next)
                {
                    next = prices[x];
                    x++;
                    if (x == prices.size()-1) 
                    {
                        if (next < prices[x]) {next = prices[x];}
                        sum = sum + next - start;
                        return sum;
                    }
                } 
                
                sum = sum + (next - start);
                
                if(x < prices.size())
                {
                    start = prices[x];
                }
            }
        }
        return sum;
    }

int main()
{
    vector<int> p{};

    // Test cases -  comment others to test one
    p = {7,1,5,3,6,4}; // ans = 7
    p = {6,1,3,2,4,7}; // ans = 7
    p = {1,2,3,4,5,6}; // ans = 5
    p = {6,5,4,3,2,1}; // ans = 0
    p = {6,4,5,3,2,1}; // ans = 1

    // Result
    int sum = maxProfit(p);
    cout << sum << '\n';
    return 0;
}
