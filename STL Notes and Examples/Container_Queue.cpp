/*
 * C++ STL CONTAINER: queue
 */

#include <iostream>
#include <queue>
#include <string>
#include <list> // Included to show alternative underlying container

using namespace std;

// -----------------------------------------------------------------
// KEY CONCEPTS
// -----------------------------------------------------------------

/*
 * 1. FIFO (First-In, First-Out)
 *
 * Technical: A `queue` is a container adapter that strictly follows a
 * "First-In, First-Out" (FIFO) data structure. Elements are
 * added to the back (tail) and removed from the front (head).
 *
 * In simple words: It works exactly like a real-world line. The
 * first person to get in line is the first person to be served.
 *
 * 2. ADAPTER CONTAINER
 *
 * Technical: A `queue` is not a standalone container but an
 * "adapter." It provides a specific, restricted interface on top
 * of an underlying sequence container. By default, it uses `deque`,
 * but it can also be configured to use `list`.
 *
 * In simple words: A queue is like a special dispenser built
 * around a tube of items. The dispenser only lets you add to one
 * end and take from the other.
 */

// -----------------------------------------------------------------
// COMPLETE FUNCTION REFERENCE
// -----------------------------------------------------------------

/*
 * ELEMENT ACCESS:
 *
 * - `front()`
 * - Technical: Returns a reference to the element at the front.
 * - Simple: Look at the person at the very front of the line.
 *
 * - `back()`
 * - Technical: Returns a reference to the element at the back.
 * - Simple: Look at the person at the very end of the line.
 *
 * CAPACITY:
 *
 * - `empty()`
 * - Technical: Returns `true` if `size() == 0`.
 * - Simple: Is the line empty?
 *
 * - `size()`
 * - Technical: Returns the number of elements in the queue.
 * - Simple: How many people are in the line?
 *
 * MODIFIERS:
 *
 * - `push(val)`
 * - Technical: Appends a copy of `val` to the back of the queue.
 * - Simple: A new person joins the end of the line.
 *
 * - `emplace(args...)`
 * - Technical: Constructs an element in-place at the back.
 * - Simple: A new person appears instantly at the end of the line.
 * It's slightly more efficient.
 *
 * - `pop()`
 * - Technical: Destroys and removes the element at the front. This
 * function has a `void` return type.
 * - Simple: The person at the front of the line is served and leaves.
 *
 * - `swap(other_queue)`
 * - Technical: Swaps the contents of this queue with another
 * queue of the same type. It's an O(1) operation if the
 * underlying containers can be swapped in O(1).
 * - Simple: Instantly switch your entire line with another line.
 */

// -----------------------------------------------------------------
// COMPLEXITY ANALYSIS
// -----------------------------------------------------------------

/*
 * All standard queue operations (`push`, `pop`, `front`, `back`,
 * `size`, `empty`, `emplace`, `swap`) are extremely fast, taking
 * constant time, O(1).
 */

// -----------------------------------------------------------------
// PRACTICAL USE CASES
// -----------------------------------------------------------------

/*
 * - Breadth-First Search (BFS): A fundamental graph algorithm used
 * in everything from finding the shortest path in an unweighted
 * graph to level-order traversal in trees.
 * - Resource Management: Handling requests for a shared resource,
 * like a printer queue, in the order they were received.
 * - Buffering: Storing data in a temporary holding area, such as
 * streaming video, where data is added by one process and
 * removed by another in a sequential manner.
 */

// -----------------------------------------------------------------
// EXAMPLE: USING A DIFFERENT UNDERLYING CONTAINER
// -----------------------------------------------------------------

int main()
{
    // Standard queue, uses a deque by default
    queue<int> default_queue;

    // A queue that uses a list as its underlying container
    queue<int, list<int>> list_based_queue;

    list_based_queue.push(10);
    list_based_queue.push(20);

    cout << "Front of list-based queue: " << list_based_queue.front() << endl;
    list_based_queue.pop();
    cout << "New front: " << list_based_queue.front() << endl;

    return 0;
}