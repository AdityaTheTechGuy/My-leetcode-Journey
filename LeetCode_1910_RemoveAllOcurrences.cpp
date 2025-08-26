/*
 * LeetCode Problem: 1910. Remove All Occurrences of a Substring
 *
 * Problem Description:
 * Given two strings, `s` and `part`, perform the following operation
 * on `s` until all occurrences of the substring `part` are removed:
 *
 * - Find the leftmost occurrence of the substring `part` and remove it from `s`.
 *
 * Return `s` after removing all occurrences of `part`.
 *
 * A substring is a contiguous sequence of characters in a string.
 *
 * Example 1:
 * Input: s = "daabcbaabcbc", part = "abc"
 * Output: "dab"
 * Explanation:
 * 1. "daabcbaabcbc" -> "dabaabcbc" (remove "abc" at index 2)
 * 2. "dabaabcbc"    -> "dababc"    (remove "abc" at index 3)
 * 3. "dababc"       -> "dab"       (remove "abc" at index 3)
 * Now, "abc" does not exist in "dab".
 *
 * Example 2:
 * Input: s = "axxxxyyyyb", part = "xy"
 * Output: "ab"
 * Explanation:
 * 1. "axxxxyyyyb" -> "axxxyyyb"
 * 2. "axxxyyyb"   -> "axxyyb"
 * 3. "axxyyb"     -> "axyb"
 * 4. "axyb"       -> "ab"
 */
/*
    My Approach:
    1. We will use the find and erase functions of cpp. First we can use the while loop
    to repeatedly find the substring given to us in the main string.

    2. Then we can erase that string.*/

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {

        while (s.find(part) < s.length() && s.length() > 0) // While loop to repeatedly find the substring
        {

            s.erase(s.find(part), part.length()); // Erase the substring from the main string
        }
        return s; // Return the modified string
    }
};