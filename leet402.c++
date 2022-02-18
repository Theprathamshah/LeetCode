/**
 * @file leet402.c++
 * 
 * 
 * @author Pratham Shah (itspratham2911@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 402. Remove K Digits
Medium

4937

203

Add to List

Share
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.
 * 
 */

/**
 * @brief 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// string removeKDigits(string s, int k)
// {
//     string ans = "";
//     for (auto ele : s)
//     {
//         while (ans.back() > ele and ans.length() and k)
//         {
//             ans.pop_back();
//             k--;
//         }
//         if (ans.length() or ele != '0')
//             ans.push_back(ele);
//     }
//     while (k--)
//     {
//         ans.pop_back();
//     }
//     return ans.empty() ? "0" : ans;
// }

string removeKdigits(string num, int k)
{
    string ans = ""; // treat ans as a stack in below for loop

    for (char c : num)
    {
        while (ans.length() && ans.back() > c && k)
        {
            ans.pop_back(); // make sure digits in ans are in ascending order
            k--;            // remove one char
        }

        if (ans.length() || c != '0')
        {
            ans.push_back(c);
        } // can't have leading '0'
    }

    while (ans.length() && k--)
    {
        ans.pop_back();
    } // make sure remove k digits in total

    return ans.empty() ? "0" : ans;
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << removeKdigits(s, k) << endl;
    /* code */

    return 0;
}
/*

!inputs
3
"1432219"
3
"10200"
1
"10"
2

!expected

"1219"
"200"
"0"



*/