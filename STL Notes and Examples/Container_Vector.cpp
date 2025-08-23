/*
 * C++ STL CONTAINER: std::vector
 *
 * AUTHOR: Aditya Gupta
 *
 * Disclaimer: This file containes my knowledge and learning path of vector.
 *              but its formated by Gemini. ALL the code is commented out, but
 *              feel free to run it. Its all my journey trying to understand the concept.
 *
 * PURPOSE:
 * A comprehensive technical reference for the std::vector container,
 * covering key concepts, a detailed function reference, and a
 * performance analysis.
 */

#include <vector>

// -----------------------------------------------------------------
// KEY CONCEPTS
// -----------------------------------------------------------------

/*
 * 1. DYNAMIC ARRAY IMPLEMENTATION
 * A std::vector is a sequence container that encapsulates a dynamic
 * array. It stores elements in a contiguous memory block, which
 * provides efficient O(1) random access but results in O(n)
 * complexity for insertions or deletions in the middle of the
 * sequence.
 *
 * 2. SIZE vs. CAPACITY & AMORTIZED GROWTH
 * The vector maintains separate `size` (element count) and
 * `capacity` (allocated storage). When an insertion exceeds the
 * current capacity, the vector reallocates a larger block of
 * memory (typically 1.5x to 2x the old capacity) and moves all
 * elements. This expensive O(n) reallocation happens infrequently
 * enough that the amortized (average) cost of `push_back` remains O(1).
 *
 * 3. IN-PLACE CONSTRUCTION (`emplace` vs. `insert`)
 * `emplace_back` and `emplace` construct objects directly in place
 * within the vector's memory, forwarding arguments to the
 * constructor. This avoids the creation of a temporary object that
 * `push_back` and `insert` require, making `emplace` operations
 * generally more efficient for non-trivial object types.
 *
 * 4. ITERATOR INVALIDATION
 * Any operation that causes a reallocation (e.g., `push_back` when
 * size == capacity) invalidates ALL iterators, pointers, and
 * references to vector elements. Insertions and deletions at a
 * given position invalidate all iterators at or after that position.
 */

// -----------------------------------------------------------------
// FUNCTION REFERENCE
// -----------------------------------------------------------------

/*
 * CONSTRUCTORS:
 * - vector() -> Creates an empty vector.
 * - vector(n, val) -> Creates a vector with n copies of val.
 * - vector(other) -> Copy constructor.
 * - vector(begin, end) -> Constructs with elements from a range.
 *
 * MODIFIERS:
 * - push_back(val) -> Appends a copy of val to the end.
 * - emplace_back(args...) -> Constructs an element in-place at the end.
 * - pop_back() -> Removes the last element.
 * - insert(pos, val) -> Inserts val before the iterator pos. Very costly as TC is O(n)
 * - emplace(pos, args...) -> Constructs an element in-place before pos.
 * - erase(pos) -> Removes the element at iterator pos.Very costly as TC is O(n)
 * - erase(first, last) -> Removes a range of elements.
 * - clear() -> Removes all elements (size becomes 0).but capacity remains same.
 * - resize(n, val) -> Changes size to n. If growing, appends copies of val.
 *
 * ELEMENT ACCESS:
 * - at(i) -> Accesses element at index i with bounds-checking.
 * - operator[i] -> Accesses element at index i without bounds-checking.
 * - front() -> Returns a reference to the first element.
 * - back() -> Returns a reference to the last element.
 * - data() -> Returns a direct pointer to the underlying C-style array.
 *
 * CAPACITY:
 * - size() -> Returns the number of elements.
 * - empty() -> Returns true if size is 0.
 * - capacity() -> Returns the size of the allocated storage.
 * - reserve(n) -> Requests a capacity of at least n.
 * - shrink_to_fit() -> Reduces capacity to match the current size.
 *
 * ITERATORS:
 * - begin() / end() -> Returns iterators to the beginning/end of the sequence.Used in functions like erase and insert
 * - rbegin() / rend() -> Returns reverse iterators for iterating backwards.
 */

// -----------------------------------------------------------------
// COMPLEXITY ANALYSIS
// -----------------------------------------------------------------

/*
 * - Random Access (v[i]): O(1)
 * - Add/Remove at End: O(1) amortized
 * - Add/Remove in Middle: O(n)
 * - Search: O(n)
 */

// Your example code (`main` function) can go here.
#include <iostream>

using namespace std;

int main()
{
    // Creating a vector
    /* vector<int> vec;  //vector<int> --> datatype of vector created | vec --> Name of the vector

     cout << vec.size() << endl; // To print the size of the vector vec, in this case, its 0.

     vec.push_back(1); //Inserting a value, size of vec= 1;

     vec.push_back(2); /*size = 2, elements 2; The size do not increase, rather a new block of double the previous size
                        *is allocated in the memory and the old data get copied. This descrease the efficiency temporarily.


     vec.push_back(3); // size = 4, elements 3;

     vector<int> three(3,1); // A vector of size 3 with each value 1;

     vector<int> vec2(vec); // Vec2 containes the value of vec only.

     vec2.erase(vec2.begin() + 1, vec.begin() + 3);    //Erase function can also work on a range, when we pass the start and the end. [start, end)
                                                          Doesnt change capacity tho. Only iterators are passed in the erase function   */

    /* for(int val: vec2){
         cout << val << " ";  //For each loop : Used when we need to surf through all the elements.
                              // Do not use if particular value manipulatio  is required.
     }
     */

    // vec.end(): Points to the nth positon of the vector (not n-1) which is usually garbage value

    // Loop for iterator

    /* vector<int> vecz = {1,2,3,4,5,6};

    vector<int>::iterator it;// Defining an iterator for vector
    for(it = vecz.begin(); it != vecz.end(); it++){
        cout << *(it) << " ";
    }
    cout << endl;   */

    /*  vector<int> vecz = {1,2,3,4,5,6};

      vector<int>::reverse_iterator it;// Defining an reverse iterator for vector
      for(it = vecz.rbegin(); it != vecz.rend(); it++){ //Starts from n-1 and end before the 0h index.(-1th index)
          cout << *(it) << " ";
      }
      cout << endl;  */

    // We do  not need this huge syntax for iterator for loop everytime, instead use auto.

    /*    vector<int> vecz = {1,2,3,4,5,6};

        for(auto it = vecz.rbegin(); it != vecz.rend(); it++){ //Starts from n-1 and end before the 0h index.(-1th index)
            cout << *(it) << " ";
        }
        cout<< endl;

        for(auto it = vecz.begin(); it != vecz.end(); it++){
            cout << *(it) << " ";
        }
        cout << endl;
    */

    return 0;
}