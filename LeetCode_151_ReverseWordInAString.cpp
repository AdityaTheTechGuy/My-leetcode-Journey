/*
 * LeetCode Problem: 151. Reverse Words in a String
 *
 * Problem Description:
 * Given an input string `s`, reverse the order of the words.
 *
 * A word is defined as a sequence of non-space characters. The
 * words in `s` will be separated by at least one space.
 *
 * Return a string of the words in reverse order concatenated by a
 * single space.
 *
 * Note that `s` may contain leading or trailing spaces or multiple
 * spaces between two words. The returned string should only have a
 * single space separating the words. Do not include any extra spaces.
 *
 * Example 1:
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 *
 * Example 2:
 * Input: s = "  hello world  "
 * Output: "world hello"
 */
/*
 * My Approach:
 * 1: First reverse the whole string.
 * 2: Then run a loop on the string and using a while loop, find the next space or end of string.
 * 3: Reverse the substring from the start to the end-1.
 * 4: Add the substring to the result string.
 *
 */

class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        string ans = "";

        for (int i = 0; i < s.length(); i++)
        {

            string word = "";

            while (s[i] != ' ' && i < s.length())
            {

                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());

            if (word.length() > 0)
            {
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};
