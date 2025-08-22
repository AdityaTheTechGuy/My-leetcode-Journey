/*
 * LeetCode Problem: 88. Merge Sorted Array

  Problem Description:
  You are given two integer arrays, `nums1` and `nums2`, sorted in
  non-decreasing order, and two integers, `m` and `n`, representing
  the number of elements in `nums1` and `nums2` respectively.

  Your task is to merge `nums2` into `nums1` to form a single array
  sorted in non-decreasing order.

  Constraints:
  - The final sorted array should not be returned by the function but
  should be stored inside the array `nums1`.
  - To accommodate this, `nums1` has a length of `m + n`. The first `m`
  elements are the ones to be merged, and the last `n` elements are
  set to 0 and should be ignored.
  - `nums2` has a length of `n`.

  Example:
  Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 Output: [1,2,2,3,5,6]
 */

class Solution
{
public:
    void merge(vector<int> &A, int m, vector<int> &B, int n)
    {
        int idx = m + n - 1, i = m - 1, j = n - 1;

        while (i >= 0 && j >= 0)
        {
            if (A[i] >= B[j])
            {
                A[idx--] = A[i--];
            }
            else
            {
                A[idx--] = B[j--];
            }
        }

        while (j >= 0)
        {
            A[idx--] =
                B[j--]; // Case if the i becomes negative then we just enter the remaining elements in the first array
        }
    }
};