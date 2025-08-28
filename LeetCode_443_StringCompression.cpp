/*
 * LeetCode Problem: 443. String Compression
 *
 * Problem Description:
 * Given an array of characters `chars`, compress it using the
 * following algorithm:
 *
 * Begin with an empty string `s`. For each group of consecutive
 * repeating characters in `chars`:
 * - If the group's length is 1, append the character to `s`.
 * - Otherwise, append the character followed by the group's length.
 *
 * The compressed string `s` should not be returned separately, but
 * instead, be stored in the input character array `chars`. After
 * you are done modifying the input array, return the new length of
 * the array.
 *
 * You must solve it using only O(1) extra space.
 *
 * Example 1:
 * Input: chars = ["a","a","b","b","c","c","c"]
 * Output: Return 6, and the first 6 characters of the input array
 * should be: ["a","2","b","2","c","3"]
 *
 * Example 2:
 * Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b"]
 * Output: Return 4, and the first 4 characters of the input array
 * should be: ["a","b","1","2"]
 */
/*
 * My approach:
 * Using Nested loops..
 * outer for loop to traverse the array.
 * inner while loop to count the number of consecutive repeating characters.
 * If count is 1, just add the character to the result.
 * If count is more than 1, add the character and the count to the result.
 * using to_string function to convert int to string.
 * Finally, copy the result to the input array and return the size of the result.
 * Time complexity: O(n)
 * Space complexity: O(1)
 * Note: The space complexity is O(1) because we are not using any extra space
 * other than the input array. The result string is not considered as extra space
 * because we are modifying the input array itself.
 */

// Code:
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int idx = 0;

        for (int i = 0; i < n; i++)
        {

            char ch = chars[i];
            int count = 0;

            while (i < n && chars[i] == ch)
            {
                count++;
                i++;
            }
            if (count == 1)
                chars[idx++] = ch;
            else
            {
                chars[idx++] = ch;
                string str = to_string(count);

                for (char dig : str)
                {
                    chars[idx++] = dig;
                }
            }
            i--;
        }
        return idx;
    }
};

// Dry Run Example:
//  Input: chars = ["a","a","b","b","c","c","c"]
//  Output: Return 6, and the first 6 characters of the input array
//  should be: ["a","2","b","2","c","3"]
//  i=0, ch='a', count=0
//  while loop: count=2, i=2
//  count>1, chars[0]='a', chars[1]='2', idx=2
//  i=2, ch='b', count=0
//  while loop: count=2, i=4
//  count>1, chars[2]='b', chars[3]='2', idx=4
//  i=4, ch='c', count=0
//  while loop: count=3, i=7
//  count>1, chars[4]='c', chars[5]='3', idx=6
//  return 6
