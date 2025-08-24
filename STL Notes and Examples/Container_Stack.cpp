/*
 * C++ STL CONTAINER: stack
 */

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

// -----------------------------------------------------------------
// KEY CONCEPTS
// -----------------------------------------------------------------

/*
 * 1. LIFO (Last-In, First-Out)
 * A `stack` is a container that operates on a "Last-In, First-Out"
 * (LIFO) principle.
 *
 * Analogy: Think of a stack of plates. You can only add a new
 * plate to the top, and you can only remove the topmost plate. The
 * last plate you put on is the first one you take off.
 *
 * 2. ADAPTER CONTAINER
 * A `stack` is not a new type of container itself; it's an
 * "adapter." It takes an underlying container (like a `vector` or,
 * by default, a `deque`) and provides a restricted, simplified
 * interface with only stack-like operations (`push`, `pop`, `top`).
 * You cannot access elements in the middle of a stack.
 */

// -----------------------------------------------------------------
// FUNCTION REFERENCE
// -----------------------------------------------------------------

/*
 * MODIFIERS:
 * - push(val) -> Adds an element to the top of the stack.
 * - emplace(args...) -> Constructs an element in-place at the top.
 * - pop() -> Removes the top element. Note: This function does
 * not return the element.
 *
 * ELEMENT ACCESS:
 * - top() -> Returns a reference to the top element of the stack.
 * You must call `top()` *before* you call `pop()` if you want
 * to get the value of the element you are removing.
 *
 * CAPACITY:
 * - size() -> Returns the number of elements in the stack.
 * - empty() -> Returns true if the stack is empty.
 */

// -----------------------------------------------------------------
// COMPLEXITY ANALYSIS
// -----------------------------------------------------------------

/*
 * All standard stack operations (`push`, `pop`, `top`, `size`, `empty`)
 * take constant time, O(1).
 */

// -----------------------------------------------------------------
// PRACTICAL USE CASES
// -----------------------------------------------------------------

/*
 * Stacks are fundamental in computer science and are used for:
 *
 * - Function Call Management: The "call stack" keeps track of
 * active function calls in a program.
 * - Expression Evaluation: Converting infix expressions to postfix
 * (e.g., "3 + 4" to "3 4 +") and evaluating them.
 * - Backtracking Algorithms: Such as navigating a maze. If you
 * hit a dead end, you "pop" back to the last decision point.
 * - Undo/Redo Functionality: Each action is "pushed" onto a stack.
 * "Undo" is simply a "pop" operation.
 */

// -----------------------------------------------------------------
// EXAMPLE USAGE
// -----------------------------------------------------------------

int main()
{
    // Create a stack of strings
    stack<string> books;

    // Check if it's empty
    if (books.empty())
    {
        cout << "The stack of books is currently empty." << endl;
    }

    // Push elements onto the stack
    books.push("The Lord of the Rings");
    books.push("Dune");
    books.push("Foundation"); // This is now the top element

    cout << "\nThere are " << books.size() << " books on the stack." << endl;
    cout << "The book on top is: '" << books.top() << "'" << endl;

    // Pop the top element
    cout << "\nRemoving the top book..." << endl;
    books.pop();

    cout << "Now, the book on top is: '" << books.top() << "'" << endl;

    // Swap the elements of two stacks

    stack<string> books2;

    books2.swap(books);

    cout << "The size of books2 is: " << books2.size() << endl;

    return 0;
}