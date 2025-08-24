/*
 * C++ STL NOTES: The reverse Algorith
 *
 * PURPOSE:
 * A complete, all-in-one reference and example file for the
 * std::reverse function from the <algorithm> header.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for std::reverse

using namespace std;

// -----------------------------------------------------------------
// THEORY & CONCEPTS
// -----------------------------------------------------------------

/*
 * The `std::reverse` function is a simple and efficient algorithm
 * for reversing the order of elements within a given range.
 *
 * CONCEPT 1: In-Place Operation
 * `reverse` modifies the container directly (in-place). It does not
 * create a new, reversed copy of the container.
 *
 * CONCEPT 2: Iterator-Based Range
 * Like `sort`, `reverse` operates on a range defined by two
 * iterators: `[first, last)`. It will reverse all elements
 * starting from the `first` iterator up to, but not including,
 * the `last` iterator. This makes it flexible enough to work on
 * whole containers or just specific parts of them.
 *
 * COMPLEXITY:
 * The complexity is linear, O(n), as it needs to swap roughly
 * half of the elements in the range.
 */

// -----------------------------------------------------------------
// CODE EXAMPLES
// -----------------------------------------------------------------

// Example 1: Reversing a whole vector
void reverse_vector_example()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Original vector: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    // Reverse the entire vector
    reverse(nums.begin(), nums.end());

    cout << "Reversed vector: ";
    for (int num : nums)
        cout << num << " "; // Expected: 5 4 3 2 1
    cout << endl;
}

// Example 2: Reversing a sub-segment of a vector
void reverse_subarray_example()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    cout << "Original vector: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    // Reverse only the middle part (from index 2 to 4)
    // Range is [nums.begin() + 2, nums.begin() + 5)
    reverse(nums.begin() + 2, nums.begin() + 5);

    cout << "With sub-array reversed: ";
    for (int num : nums)
        cout << num << " "; // Expected: 1 2, 5 4 3, 6 7
    cout << endl;
}

// Example 3: Reversing a C-style array
void reverse_c_style_array_example()
{
    int nums[] = {10, 20, 30, 40, 50};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "Original C-style array: ";
    for (int i = 0; i < n; ++i)
        cout << nums[i] << " ";
    cout << endl;

    // Reverse the array using pointers
    reverse(nums, nums + n);

    cout << "Reversed C-style array: ";
    for (int i = 0; i < n; ++i)
        cout << nums[i] << " "; // Expected: 50 40 30 20 10
    cout << endl;
}

int main()
{
    cout << "--- 1. Reversing a Whole Vector ---" << endl;
    reverse_vector_example();

    cout << "\n--- 2. Reversing a Sub-Array ---" << endl;
    reverse_subarray_example();

    cout << "\n--- 3. Reversing a C-style Array ---" << endl;
    reverse_c_style_array_example();

    return 0;
}