/*

BACKSPACE STRING COMPARE

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // function to evaluate the backspace in string
    vector<char> back_spaces(vector<char> S_new) {
        int count = S_new.size(), flag = 0, retrieve = 0;
    
        while (count > 0)
        {
            retrieve = 0;
            while (S_new[count-1] == '#' && count > 0)
            {
                S_new.erase(S_new.begin()+count-1);
                count = S_new.size()-1;
                flag++;
            }
            while (flag != 0 && count >= 0) 
            {
                S_new.erase(S_new.begin()+count-1);
                count = S_new.size();
                flag--;
                retrieve = 1;
            }
            if (retrieve == 0) { if (count > 0) {count--;} }
        }

        return S_new;
    }

    // function to compare the evaluated strings
    bool backspaceCompare(string S, string T) {
        vector<char> S_new(S.begin(), S.end());
        vector<char> T_new(T.begin(), T.end());

        vector<char> S_processed = back_spaces(S_new);
        vector<char> T_processed = back_spaces(T_new);
        
        if (S_processed == T_processed) {return true;}
        else {return false;}
    }
};

int main()
{
    /* Test cases - comment others to test one */ 
    // string S = "a#c", T = "b"; // ans = False
    // string S = "ab#c", T = "ad#c"; // ans = True
    string S = "ab##", T = "c#d#"; // ans = True
    // string S = "a##c", T = "#a#c"; // ans = True

    /* Result */
    Solution sol;
    bool result = sol.backspaceCompare(S, T);

    /* Display */
    if (result == 1){cout << "True" << endl;}
    else{cout << "False" << endl;}
}