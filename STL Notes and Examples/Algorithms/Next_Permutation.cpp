/*
 * C++ STL NOTES: The next_permutation Algorithm
 *
 * PURPOSE:
 * A complete, all-in-one reference and example file for the
 * std::next_permutation function from the <algorithm> header.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for std::next_permutation and std::sort

using namespace std;

// -----------------------------------------------------------------
// THEORY & CONCEPTS
// -----------------------------------------------------------------

/*
 * The `std::next_permutation` function is a powerful algorithm that
 * rearranges the elements in a range into the next lexicographically
 * greater permutation.
 *
 * CONCEPT 1: Lexicographical Order
 * This is essentially "dictionary order." For numbers, it's the
 * order you'd find them on a number line.
 * Example: For {1,2,3}, the order is:
 * 1. {1,2,3}
 * 2. {1,3,2}
 * 3. {2,1,3}
 * 4. {2,3,1}
 * 5. {3,1,2}
 * 6. {3,2,1}
 * `next_permutation` of {2,1,3} is {2,3,1}.
 *
 * CONCEPT 2: In-Place Operation
 * The function modifies the container directly (in-place).
 *
 * CONCEPT 3: Return Value
 * It returns `true` if a greater permutation was found and the
 * range was rearranged. It returns `false` if the range is already
 * at its highest possible permutation (like {3,2,1}), in which case
 * it rearranges the range to the lowest possible order (sorted,
 * like {1,2,3}).
 *
 * COMPLEXITY:
 * The complexity is linear, O(n), as it performs at most n/2 swaps.
 */

// -----------------------------------------------------------------
// CODE EXAMPLES
// -----------------------------------------------------------------

// Helper function to print a vector
void printVector(const string &message, const vector<int> &nums)
{
    cout << message;
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Example 1: Finding the next permutation of a simple vector
void find_next_example()
{
    vector<int> nums = {1, 3, 2};
    printVector("Original vector:    ", nums);

    // Find the next permutation
    next_permutation(nums.begin(), nums.end());

    printVector("Next permutation:     ", nums); // Expected: 2 1 3
}

// Example 2: The "last" permutation case
void last_permutation_example()
{
    vector<int> nums = {3, 2, 1};
    printVector("Original vector (last perm): ", nums);

    // Attempt to find the next permutation
    bool result = next_permutation(nums.begin(), nums.end());

    cout << "Function returned: " << (result ? "true" : "false") << endl; // Expected: false
    printVector("Resulting vector (lowest perm):", nums);                 // Expected: 1 2 3
}

// Example 3: Generating ALL permutations
void generate_all_permutations_example()
{
    vector<int> nums = {1, 2, 3};

    // IMPORTANT: To generate all permutations, you MUST start with
    // the sequence sorted in ascending order.
    sort(nums.begin(), nums.end());

    cout << "All permutations of {1, 2, 3}:" << endl;
    do
    {
        printVector("- ", nums);
    } while (next_permutation(nums.begin(), nums.end()));
}

int main()
{
    cout << "--- 1. Finding a Single Next Permutation ---" << endl;
    find_next_example();

    cout << "\n--- 2. Handling the Last Permutation ---" << endl;
    last_permutation_example();

    cout << "\n--- 3. Generating All Permutations ---" << endl;
    generate_all_permutations_example();

    return 0;
}