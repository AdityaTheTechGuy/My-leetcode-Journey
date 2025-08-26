/*
 * LeetCode Problem: 125. Valid Palindrome
 *
 * Problem Description:
 * A phrase is a palindrome if after converting all uppercase letters
 * into lowercase letters and removing all non-alphanumeric characters,
 * it reads the same forward and backward. Alphanumeric characters
 * include letters and numbers.
 *
 * Given a string `s`, return `true` if it is a palindrome, or
 * `false` otherwise.
 *
 * Example 1:
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 *
 * Example 2:
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 */

/* My approach:
 *             First we will sanitize the string by removing all the non alphanumeric characters.
 * And also converting all uppercase letters to lower case using tolower() in cpp.
 *
 * Second, we will use the simple two pointer approah and compare the chracters of the string to
 * check if it is a palindrome or not.
 */

class Solution
{
public:
    bool isAlphaNum(char ch)
    {
        if ((ch >= '0' && ch <= '9') ||
            (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
        {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s)
    {
        int n = s.length();
        int st = 0, end = n - 1;

        while (st < end)
        {
            if (!isAlphaNum(s[st]))
            {
                st++;
                continue;
            }
            if (!isAlphaNum(s[end]))
            {
                end--;
                continue;
            }
            if (tolower(s[st]) != tolower(s[end]))
            {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};