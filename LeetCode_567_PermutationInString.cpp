/*
 * LeetCode Problem: 567. Permutation in String
 *
 * Problem Description:
 * Given two strings, `s1` and `s2`, return `true` if `s2` contains a
 * permutation of `s1`, or `false` otherwise.
 *
 * In other words, return `true` if one of `s1`'s permutations is a
 * substring of `s2`.
 *
 * Example 1:
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 * Example 2:
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 */

/*
 *  My Approach:
 *
 * 1. We will use the sliding window technique to solve this problem.
 *
 * 2. We will maintain a frequency array for the characters in s1, basically it will contain the info
 * like how many characters are there and how often they occur in the string s1.
 *
 * But this won't work if there are more variations of characters in the string. So we will use an unordered_map
 * to store the frequency of characters in s1 if the contraints are not given.
 *
 * 3. Then we will use two pointers to maintain a window of size equal to the size of s1
 * and we will keep on moving the window and updating the frequency array for the characters in the window.
 *
 * */

class Solution
{
public:
    bool isFreqSame(int freq1[], int freq2[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] != freq2[i])
            {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2)
    {

        int freq[26] = {0};

        for (int i = 0; i < s1.length(); i++)
        {
            freq[s1[i] - 'a']++;
        }

        int windsize = s1.length();

        for (int i = 0; i < s2.length(); i++)
        {
            int windidx = 0, idx = i, windfreq[26] = {0};

            while ((windidx < windsize) && idx < s2.length())
            {
                windfreq[s2[idx] - 'a']++;
                windidx++;
                idx++;
            }

            if (isFreqSame(freq, windfreq))
            {
                return true;
            }
        }

        return false;
    }
};