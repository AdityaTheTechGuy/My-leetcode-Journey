/*
 * C++ STL CONTAINER: list
 */

#include <iostream>
#include <list>
#include <string>
#include <vector> // Included for comparison purposes

using namespace std;

// -----------------------------------------------------------------
// KEY CONCEPTS
// -----------------------------------------------------------------

/*
 * 1. DOUBLY-LINKED LIST IMPLEMENTATION
 * A `list` is not an array. It is implemented as a doubly-linked
 * list, where each element is a separate node in memory that
 * holds the data and two pointers: one to the previous element
 * and one to the next.
 *
 * 2. KEY TRADE-OFF: FAST INSERTIONS, SLOW ACCESS
 * Because elements are just nodes with pointers, inserting or
 * deleting an element in the middle of a list is very fast (O(1))
 * *if you already have an iterator to that position*. However,
 * there is no direct random access (you can't use `my_list[i]`).
 * To get to the nth element, you must walk the list from the
 * beginning or end, which is slow (O(n)).
 *
 * 3. ITERATOR STABILITY
 * Unlike a vector, inserting or deleting elements in a list
 * does NOT invalidate iterators, pointers, or references to other
 * elements in the list.
 */

// -----------------------------------------------------------------
// FUNCTION REFERENCE
// -----------------------------------------------------------------

/*
 * MODIFIERS:
 * - push_back(val) -> Adds an element to the end.
 * - emplace_back(args...) -> Constructs an element in-place at the end.
 * - pop_back() -> Removes the last element.
 * - push_front(val) -> Adds an element to the beginning. (Fast O(1))
 * - emplace_front(args...) -> Constructs an element in-place at the beginning.
 * - pop_front() -> Removes the first element. (Fast O(1))
 * - insert(pos, val) -> Inserts val before the iterator pos. (Fast O(1))
 * - erase(pos) -> Removes the element at iterator pos. (Fast O(1))
 * - clear() -> Removes all elements.
 *
 * ELEMENT ACCESS:
 * - front() -> Returns a reference to the first element.
 * - back() -> Returns a reference to the last element.
 *
 * CAPACITY:
 * - size() -> Returns the number of elements.
 * - empty() -> Returns true if size is 0.
 *
 * OPERATIONS:
 * - sort() -> Sorts the list in-place.
 * - merge(other) -> Merges another sorted list into this one.
 * - reverse() -> Reverses the order of elements.
 * - unique() -> Removes consecutive duplicate elements.
 */

// -----------------------------------------------------------------
// COMPLEXITY ANALYSIS
// -----------------------------------------------------------------

/*
 * - Access (to nth element): O(n)
 * - Search: O(n)
 * - Add/Remove at Start, Middle, or End: O(1) (if you have an iterator)
 */

// -----------------------------------------------------------------
// WHEN TO USE `list` vs. `vector`
// -----------------------------------------------------------------

/*
 * - Use `vector` (DEFAULT CHOICE): When you need fast random
 * access (`v[i]`) and most of your insertions/deletions are
 * at the end.
 * - Use `list`: When you have a large list and will be doing
 * frequent insertions and deletions in the middle of the list.
 */

int main()
{

    /*list<int> l = {1,2,3,4,5};

    for(int val: l){

        cout << val << " ";
    }
    cout<< endl;
    */
    return 0;
}