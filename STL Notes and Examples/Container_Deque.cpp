/*
 * C++ STL CONTAINER: deque
 *
 * AUTHOR: Aditya Gupta
 * DATE: August 24, 2025
 */

#include <iostream>
#include <deque>
#include <string>

using namespace std;

// -----------------------------------------------------------------
// KEY CONCEPTS
// -----------------------------------------------------------------

/*
 * 1. "DOUBLE-ENDED QUEUE" IMPLEMENTATION
 * A `deque` (pronounced "deck") stands for Double-Ended Queue.
 * It is a sequence container that allows for fast insertions and
 * deletions at both its beginning and its end.
 *
 * 2. INTERNAL STRUCTURE & KEY TRADE-OFF
 * Unlike a vector (one contiguous block of memory) or a list (many
 * separate nodes), a deque is usually implemented as a sequence of
 * fixed-size arrays (or "chunks") of memory. This structure provides
 * a balance between the strengths of vectors and lists:
 * - It allows for fast O(1) insertions at both the front and back.
 * - It allows for fast O(1) random access (`my_deque[i]`).
 * The trade-off is that it has slightly higher overhead for its
 * iterators compared to a vector's simple pointers.
 *
 * 3. ITERATOR INVALIDATION
 * Inserting or deleting elements in the middle of a deque invalidates
 * ALL iterators, pointers, and references. However, insertions at the
 * front or back only invalidate iterators if a reallocation of the
 * internal array chunks occurs.
 */

// -----------------------------------------------------------------
// FUNCTION REFERENCE
// -----------------------------------------------------------------

/*
 * MODIFIERS:
 * - push_back(val) -> Adds an element to the end. (Fast O(1))
 * - emplace_back(args...) -> Constructs an element in-place at the end.
 * - pop_back() -> Removes the last element.
 * - push_front(val) -> Adds an element to the beginning. (Fast O(1))
 * - emplace_front(args...) -> Constructs an element in-place at the beginning.
 * - pop_front() -> Removes the first element.
 * - insert(pos, val) -> Inserts val before the iterator pos. (Slow O(n))
 * - erase(pos) -> Removes the element at iterator pos.
 * - clear() -> Removes all elements.
 *
 * ELEMENT ACCESS:
 * - at(i) -> Accesses element at index i with bounds-checking.
 * - operator[i] -> Accesses element at index i without bounds-checking.
 * - front() -> Returns a reference to the first element.
 * - back() -> Returns a reference to the last element.
 *
 * CAPACITY:
 * - size() -> Returns the number of elements.
 * - empty() -> Returns true if size is 0.
 * - shrink_to_fit() -> Frees unused memory.
 */

// -----------------------------------------------------------------
// COMPLEXITY ANALYSIS
// -----------------------------------------------------------------

/*
 * - Random Access (dq[i]): O(1)
 * - Add/Remove at End or Start: O(1)
 * - Add/Remove in Middle: O(n)
 */

// -----------------------------------------------------------------
// WHEN TO USE `deque`
// -----------------------------------------------------------------

/*
 * - Use `vector` (DEFAULT): When you need fast random access and
 * most insertions/deletions are at the end.
 *
 * - Use `list`: When you have frequent insertions/deletions in the
 * middle of a large sequence.
 *
 * - Use `deque`: When you need the features of a vector (fast random
 * access) but also need fast insertions and deletions at the
 * *beginning* of the sequence as well as the end. A perfect
 * example is implementing a sliding window algorithm.
 */
#include <iostream>

int main()
{
    // not much code, as it is all similar to vector and list.

    return 0;
}