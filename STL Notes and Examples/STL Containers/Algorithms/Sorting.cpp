/*
 * C++ STL NOTES: A Comprehensive Guide to Sorting
 *
 * PURPOSE:
 * A complete, all-in-one reference and example file for the
 * std::sort function from the <algorithm> header.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // Required for std::sort
#include <functional> // Required for std::greater
#include <utility>    // Required for std::pair

using namespace std;

// -----------------------------------------------------------------
// THEORY & CONCEPTS
// -----------------------------------------------------------------

/*
 * The `std::sort` function is the primary tool for sorting in C++.
 * It is a highly optimized algorithm (typically an IntroSort, a
 * hybrid of QuickSort, HeapSort, and InsertionSort).
 *
 * CONCEPT 1: Basic Sorting (Ascending Order)
 * The simplest way to use `sort` is to give it two iterators: a
 * pointer to the beginning and a pointer to the end of the range
 * you want to sort. It sorts in ascending order by default.
 *
 * CONCEPT 2: Sorting in Descending Order
 * To change the order, you can provide a third argument: a
 * "comparator." The standard library provides `greater<T>()` for
 * descending order.
 *
 * CONCEPT 3: Sorting Custom Objects
 * You can sort any collection of objects (like a struct) by
 * providing your own custom comparison function. This function
 * takes two objects and returns `true` if the first should come
 * before the second.
 *
 * CONCEPT 4: Advanced Sorting & Edge Cases
 * - Sorting Pairs: By default, pairs are sorted by their `first`
 * element. A custom comparator is needed to sort by the `second`.
 * - Lambda Functions: For simple, one-off comparisons, a lambda
 * function can be used as an "inline" comparator.
 * - Sub-segment Sorting: `sort` can be applied to any range
 * within a container, not just the whole thing.
 */

// -----------------------------------------------------------------
// CODE EXAMPLES
// -----------------------------------------------------------------

// Example 1: Basic Ascending Sort
void basic_sorting_example()
{
    vector<int> nums = {5, 2, 8, 1, 9, 4};
    cout << "Original vector: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    sort(nums.begin(), nums.end());

    cout << "Sorted vector:   ";
    for (int num : nums)
        cout << num << " "; // Expected: 1 2 4 5 8 9
    cout << endl;
}

// Example 2: Descending Sort
void descending_sorting_example()
{
    vector<int> nums = {5, 2, 8, 1, 9, 4};
    sort(nums.begin(), nums.end(), greater<int>());

    cout << "Sorted descending: ";
    for (int num : nums)
        cout << num << " "; // Expected: 9 8 5 4 2 1
    cout << endl;
}

// Example 3: Sorting a vector of custom structs
struct Student
{
    string name;
    int score;
};

// Custom comparator function for the Student struct
bool compareStudents(const Student &a, const Student &b)
{
    return a.score > b.score; // Sort by score, highest first
}

void custom_sorting_example()
{
    vector<Student> students = {{"Aditya", 95}, {"Rohan", 88}, {"Priya", 98}};
    sort(students.begin(), students.end(), compareStudents);

    cout << "Student Leaderboard:" << endl;
    for (const auto &student : students)
    {
        cout << student.name << ": " << student.score << endl;
    }
}

// Example 4: Sorting a vector of pairs by the second element
bool comparePairs(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

void pair_sorting_example()
{
    vector<pair<int, int>> pairs = {{1, 40}, {2, 30}, {3, 50}};
    sort(pairs.begin(), pairs.end(), comparePairs);

    cout << "Pairs sorted by second element:" << endl;
    for (const auto &p : pairs)
    {
        cout << "{" << p.first << ", " << p.second << "} ";
    }
    cout << endl;
}

// Example 5: Sorting with a Lambda function (modern C++)
void lambda_sorting_example()
{
    vector<pair<int, int>> pairs = {{1, 40}, {2, 30}, {3, 50}};

    sort(pairs.begin(), pairs.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    cout << "Pairs sorted by second element (using lambda):" << endl;
    for (const auto &p : pairs)
    {
        cout << "{" << p.first << ", " << p.second << "} ";
    }
    cout << endl;
}

// Example 6: Sorting just a sub-segment of a vector
void subarray_sorting_example()
{
    vector<int> nums = {5, 2, 8, 1, 9, 4};

    // Sort only from the 2nd element (index 1) to the 5th element (index 4)
    sort(nums.begin() + 1, nums.begin() + 5);

    cout << "Vector with sub-array sorted: ";
    for (int num : nums)
        cout << num << " "; // Expected: 5, 1, 2, 8, 9, 4
    cout << endl;
}

int main()
{
    cout << "--- 1. Basic Sorting ---" << endl;
    basic_sorting_example();

    cout << "\n--- 2. Descending Sorting ---" << endl;
    descending_sorting_example();

    cout << "\n--- 3. Custom Object Sorting ---" << endl;
    custom_sorting_example();

    cout << "\n--- 4. Advanced: Pair Sorting ---" << endl;
    pair_sorting_example();

    cout << "\n--- 5. Advanced: Lambda Sorting ---" << endl;
    lambda_sorting_example();

    cout << "\n--- 6. Edge Case: Sub-array Sorting ---" << endl;
    subarray_sorting_example();

    return 0;
}