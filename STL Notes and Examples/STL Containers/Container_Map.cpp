/*
 * C++ STL CONTAINER: The Map Family
 */

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// -----------------------------------------------------------------
// KEY CONCEPT: KEY-VALUE PAIRS
// -----------------------------------------------------------------

/*
 * Technical: Maps are associative containers that store elements
 * formed by a combination of a key and a mapped value.
 *
 * In simple words: All maps are like dictionaries. You look up a
 * unique "key" (the word) to find its associated "value" (the
 * definition).
 */

// -----------------------------------------------------------------
// 1. std::map
// -----------------------------------------------------------------

/*
 * The Ordered Dictionary
 *
 * Underlying Structure: Self-Balancing Binary Search Tree (Red-Black Tree).
 *
 * Key Characteristics:
 * - Sorted Order: Keys are always kept in sorted order. Iterating
 * through the map will be in ascending order of keys.
 * - Unique Keys: Each key must be unique.
 * - Performance: O(log n) for search, insertion, and deletion.
 *
 * When to use: When you need your data automatically sorted by its
 * key, or when you need to find elements within a certain range
 * (e.g., all employees with IDs between 1000 and 2000).
 */

// -----------------------------------------------------------------
// 2. std::unordered_map
// -----------------------------------------------------------------

/*
 * The Fast Dictionary
 *
 * Underlying Structure: Hash Table.
 *
 * Key Characteristics:
 * - Unordered: Keys are not stored in any particular order.
 * - Unique Keys: Each key must be unique.
 * - Performance: Average case O(1) for search, insertion, and
 * deletion. This makes it significantly faster than a regular map
 * for most operations.
 *
 * When to use: This should be your **default choice** for a dictionary
 * unless you specifically need the keys to be sorted. Its O(1)
 * average performance is a huge advantage.
 */

// -----------------------------------------------------------------
// 3. std::multimap
// -----------------------------------------------------------------

/*
 * The Dictionary with Duplicates
 *
 * Underlying Structure: Self-Balancing Binary Search Tree (like std::map).
 *
 * Key Characteristics:
 * - Sorted Order: Keys are always kept in sorted order.
 * - Duplicate Keys Allowed: This is its main feature. You can have
 * multiple entries with the exact same key.
 * - Performance: O(log n) for search, insertion, and deletion.
 *
 * When to use: When you need a dictionary-like structure but have
 * to associate multiple values with a single key. For example, a
 * dictionary where the key is a word and the values are all its
 * different definitions.
 */

// -----------------------------------------------------------------
// COMMON FUNCTION REFERENCE
// -----------------------------------------------------------------

/*
 * Note: These functions are common to both `map` and `unordered_map`.
 * `multimap` does not have `operator[]` or `at()`.
 *
 * ELEMENT ACCESS & MODIFIERS:
 *
 * - `operator[]`
 * - Technical: Accesses or inserts an element. If the key does not
 * exist, it is inserted with a default-constructed value.
 * - Simple: The quickest way to get or set a value.
 *
 * - `insert({key, value})`
 * - Technical: Inserts a key-value pair.
 * - Simple: A safe way to add an entry (won't overwrite in `map`).
 *
 * - `at(key)`
 * - Technical: Accesses the value, throws an exception if key is not found.
 * - Simple: A safer way to get a value.
 *
 * - `erase(key)` -> Removes elements with the given key.
 *
 * SEARCHING:
 *
 * - `find(key)` -> Returns an iterator to the element, or `::end()` if not found.
 * - `count(key)` -> Returns the number of elements with the given key.
 *
 * CAPACITY:
 * - `empty()` -> Is the map empty?
 * - `size()` -> How many key-value pairs are in the map?
 */

// -----------------------------------------------------------------
// COMPLEXITY & USE CASE SUMMARY
// -----------------------------------------------------------------
/*
| Container       | Complexity | Sorting         | Duplicate Keys? | Best For                                        |
|-----------------|------------|-----------------|-----------------|-------------------------------------------------|
| `map`           | O(log n)   | Yes, by key     | No              | Ordered data, range searches.                   |
| `unordered_map` | O(1) avg.  | No              | No              | Fast lookups, your default choice.              |
| `multimap`      | O(log n)   | Yes, by key     | Yes             | Storing multiple values for a single key.       |
*/
// -----------------------------------------------------------------
// EXAMPLE USAGE
// -----------------------------------------------------------------

int main()
{
    // 1. Unordered Map - for fast, general-purpose use
    cout << "--- Unordered Map (Fastest) ---" << endl;
    unordered_map<string, int> fast_ages;
    fast_ages["Aditya"] = 20;
    fast_ages["Rohan"] = 21;
    fast_ages["Priya"] = 20; // Note: Order is not guaranteed
    for (const auto p : fast_ages)
    {
        cout << p.first << " is " << p.second << endl;
    }

    // 2. Map - for when you need keys to be sorted
    cout << "\n--- Map (Sorted) ---" << endl;
    map<string, int> sorted_ages;
    sorted_ages["Rohan"] = 21;
    sorted_ages["Aditya"] = 20;
    sorted_ages["Priya"] = 20; // Will be printed in alphabetical order
    for (const auto p : sorted_ages)
    {
        cout << p.first << " is " << p.second << endl;
    }

    // 3. Multimap - for when you need duplicate keys
    cout << "\n--- Multimap (Duplicates Allowed) ---" << endl;
    multimap<string, string> phonebook;
    phonebook.insert({"Aditya", "111-222"});
    phonebook.insert({"Aditya", "333-444"}); // Same key, different value
    phonebook.insert({"Priya", "555-666"});
    for (const auto p : phonebook)
    {
        cout << p.first << "'s number: " << p.second << endl;
    }

    return 0;
}