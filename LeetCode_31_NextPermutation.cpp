/*
 * LeetCode Problem: 31. Next Permutation
 *
 * Problem Description:
 * A permutation of an array of integers is an arrangement of its
 * members into a sequence or linear order. The next permutation of
 * an array of integers is the next lexicographically greater
 * permutation of its integer.
 *
 * More formally, if all the permutations of the array are sorted in
 * one container according to their lexicographical order, then the
 * next permutation of that array is the permutation that follows it
 * in the sorted container.
 *
 * If such an arrangement is not possible (i.e., the array is in its
 * highest possible order), the array must be rearranged as the lowest
 * possible order (i.e., sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Examples:
 * - [1,2,3] -> [1,3,2]
 * - [2,3,1] -> [3,1,2]
 * - [3,2,1] -> [1,2,3] (as it's the largest permutation)
 *
 * Algorithm Summary:
 * 1. Find the first element from the right that is smaller than the
 * element to its right. This is the "pivot".
 * 2. Find the smallest element to the right of the pivot that is still
 * larger than the pivot. This is the "successor".
 * 3. Swap the pivot and the successor.
 * 4. Reverse the sequence of elements to the right of the pivot's
 * original position.
 */

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int pivot = -1;

        // 1st Step: Find the pivot element

        for (int i = n - 2; i >= 0; i--)
        {

            if (nums[i] < nums[i + 1])
            {
                pivot = i;
                break;
            }
        }
        if (pivot == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 2nd Step: Finding the next larger element from the right most and swap with pivot

        for (int i = n - 1; i > pivot; i--)
        {
            if (nums[i] > nums[pivot])
            {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // 3rd Step: Reverse the array on the right of the pivot

        reverse(nums.begin() + pivot + 1, nums.end());
    }
};