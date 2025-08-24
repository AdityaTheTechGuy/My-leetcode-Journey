/*
 * C++ STL CONTAINER: priority_queue
 */

#include <iostream>
#include <queue>
#include <vector>
#include <functional> // Required for std::greater
#include <string>

using namespace std;

// -----------------------------------------------------------------
// KEY CONCEPTS
// -----------------------------------------------------------------

/*
 * 1. "VIP Line" (Highest Priority First)
 *
 * Technical: A `priority_queue` is a container adapter that organizes
 * its elements in a specific order based on priority. By default, it's
 * a Max-Heap, meaning the element with the highest value is always
 * at the top and can be accessed in constant time.
 *
 * In simple words: It works like a "VIP line" or an emergency room.
 * It doesn't matter when you arrive; the most important person (the
 * highest value) is always at the front, ready to be served next.
 *
 * 2. HEAP IMPLEMENTATION
 *
 * Technical: It's internally implemented using a Heap data structure,
 * a specialized binary tree that satisfies the heap property (in a
 * Max-Heap, any parent node is greater than or equal to its children).
 * This structure allows for efficient retrieval of the max element
 * and logarithmic time for insertions and deletions.
 *
 * In simple words: Internally, it arranges the elements in a
 * clever tree-like structure so it can always find the "VIP"
 * very, very quickly.
 *
 * 3. ADAPTER CONTAINER
 *
 * Technical: Like `stack` and `queue`, it's an adapter that provides a
 * specific interface on top of an underlying container. By default, it
 * uses `vector`.
 *
 * In simple words: It's a special-purpose tool. You can't iterate
 * through it. You can only add items and access/remove the top
 * priority item.
 */

// -----------------------------------------------------------------
// FUNCTION REFERENCE
// -----------------------------------------------------------------

/*
 * ELEMENT ACCESS:
 *
 * - `top()`
 * - Technical: Returns a const reference to the top element (the one
 * with the highest priority).
 * - Simple: Look at the most important person at the front of the line.
 *
 * CAPACITY:
 *
 * - `empty()`
 * - Technical: Returns `true` if the container is empty.
 * - Simple: Is the VIP line empty?
 *
 * - `size()`
 * - Technical: Returns the number of elements.
 * - Simple: How many people are in the VIP line?
 *
 * MODIFIERS:
 *
 * - `push(val)`
 * - Technical: Adds an element to the priority queue and reorders the
 * internal heap to maintain the priority property.
 * - Simple: A new person joins the line, and everyone shuffles
 * around to make sure the most important person is still at the front.
 *
 * - `emplace(args...)`
 * - Technical: Constructs an element in-place and adds it to the queue.
 * - Simple: A new person appears in the line, and everyone
 * reorders themselves. More efficient than `push`.
 *
 * - `pop()`
 * - Technical: Removes the top element from the priority queue.
 * - Simple: The most important person is served and leaves the line.
 *
 * - `swap(other_pq)`
 * - Technical: Swaps the contents with another priority_queue.
 * - Simple: Instantly switch your VIP line with another one.
 */

// -----------------------------------------------------------------
// COMPLEXITY ANALYSIS
// -----------------------------------------------------------------

/*
 * - Accessing the top element (`top`): O(1)
 * - Adding an element (`push`, `emplace`): O(log n)
 * - Removing the top element (`pop`): O(log n)
 */

// -----------------------------------------------------------------
// HOW TO CREATE A MIN-HEAP (Smallest Element First)
// -----------------------------------------------------------------

/*
 * Technical: By default, a priority_queue is a Max-Heap. To create a
 * Min-Heap (where the smallest element is at the top), you must provide
 * two extra template arguments: the underlying container (`vector<T>`)
 * and the comparator (`greater<T>`).
 *
 * In simple words: You have to tell the "VIP line" that its priority
 * is backwards now: the *lowest* value is the most important.
 *
 * Syntax:
 * priority_queue<type, vector<type>, greater<type>> my_min_heap;
 */

// -----------------------------------------------------------------
// PRACTICAL USE CASES
// -----------------------------------------------------------------

/*
 * - Dijkstra's and Prim's Algorithms: Used to find the shortest
 * path or minimum spanning tree in a graph by always processing
 * the "closest" or "cheapest" node next. A min-heap is essential here.
 *
 * - Heap Sort: A priority_queue is the basis for this efficient
 * sorting algorithm.
 *
 * - "Top K" Problems: Finding the 'k' largest or smallest elements
 * in a collection without having to sort the entire collection.
 */

// -----------------------------------------------------------------
// EXAMPLE USAGE
// -----------------------------------------------------------------

int main()
{
    // --- Max-Heap (Default Behavior) ---
    // The largest element always has the highest priority.
    cout << "--- Max-Heap Example ---" << endl;
    priority_queue<int> max_heap;

    // Push elements into the priority queue
    max_heap.push(30);
    max_heap.push(100);
    max_heap.push(20);
    max_heap.push(50);

    // The top() element will be the largest value pushed so far.
    cout << "Top element (largest): " << max_heap.top() << endl; // Expected: 100

    // Let's see the elements in priority order
    cout << "Processing elements in Max-Heap order: ";
    while (!max_heap.empty())
    {
        cout << max_heap.top() << " "; // Print the top element
        max_heap.pop();                // Remove the top element
    }
    cout << endl; // Expected: 100 50 30 20

    cout << "\n-----------------------------\n"
         << endl;

    // --- Min-Heap (Smallest Element First) ---
    // We must provide the underlying container and the comparator.
    cout << "--- Min-Heap Example ---" << endl;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // Push elements into the priority queue
    min_heap.push(30);
    min_heap.push(100);
    min_heap.push(20);
    min_heap.push(50);

    // The top() element will be the smallest value pushed so far.
    cout << "Top element (smallest): " << min_heap.top() << endl; // Expected: 20

    // Let's see the elements in priority order
    cout << "Processing elements in Min-Heap order: ";
    while (!min_heap.empty())
    {
        cout << min_heap.top() << " "; // Print the top element
        min_heap.pop();                // Remove the top element
    }
    cout << endl; // Expected: 20 30 50 100

    return 0;
}