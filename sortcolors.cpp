class Solution
{
public:
    /*Approach 2: Most optimal method using one pass
        "Dutch National Flag Algorithm"
        -> Take three pointers named, "low", "mid" and "high"
        RULES OF ALGO:
        1. All 0s will be stored between -> 0 to low - 1
        2. All 1s will be stored between -> low to mid - 1
        3. All 2s will be stored between -> high + 1 to n - 1

        4. All unsorted elements will be stored between -> m to h

        TC = O(N) but only one pass required
        SC = 0(1)                                                                      */

    void sortColors_DNFalgo(vector<int> &nums)
    {
        int n = nums.size();

        int low = 0, mid = 0, high = n - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }

    /*Approach 1: Brute force using two passes solution.
      Pass 1 to count the number occurrences of the elements.
      Pass 2  to change the values in the array based on the count.
      TC = O(N)
      SC = O(1)                                                      */

    void sortColors_bruteforce(vector<int> &nums)
    {
        // Overall TC = O(n)
        int zeroes = 0, ones = 0, twos = 0;

        // TC = O(n)

        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i] == 0)
                zeroes++;
            else if (nums[i] == 1)
                ones++;
            else
                twos++;
        }

        // TC = O(n)

        int idx = 0;
        for (int i = 0; i < zeroes; i++)
        {
            nums[idx++] = 0;
        }
        for (int i = 0; i < ones; i++)
        {
            nums[idx++] = 1;
        }
        for (int i = 0; i < twos; i++)
        {
            nums[idx++] = 2;
        }
    }
};
