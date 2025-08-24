/*
 * C++ STL NOTES: The pair (Simple Guide)
 * AUTHOR: Aditya Gupta
 * DATE: August 24, 2025
 */

#include <iostream>
#include <utility> // Required for pair
#include <string>
#include <vector>

using namespace std;

// -----------------------------------------------------------------
// CONCEPT: WHAT IS A PAIR?
// -----------------------------------------------------------------

/*
 * In simple words: A `pair` is a small container that holds
 * exactly two items together. The two items can be of different
 * data types.
 *
 * Analogy: Think of it like a single contact card that holds
 * just two pieces of information: a person's **name** (a string)
 * and their **age** (an integer). The pair bundles these two
 * different things into one single unit.
 */

// -----------------------------------------------------------------
// HOW TO USE IT (THE ESSENTIALS)
// -----------------------------------------------------------------

/*
 * 1. CREATE A PAIR
 * You tell it what two types of data it will hold, and then give
 * it the two values.
 *
 * Syntax:
 * pair<string, int> contact = {"Aditya", 20};
 *
 *
 * 2. GET THE VALUES
 * You get the two items inside the pair using `.first` and `.second`.
 *
 * Syntax:
 * string personName = contact.first;  // Gets "Aditya"
 * int personAge = contact.second;    // Gets 20
 *
 *
 * 3. CHANGE THE VALUES
 * You can also change the values in the same way.
 *
 * Syntax:
 * contact.second = 21; // Updates the age to 21
 */

// -----------------------------------------------------------------
// A COMMON USE CASE: A LIST OF PAIRS
// -----------------------------------------------------------------

/*
 * A very common pattern is to create a `vector` (a list) where
 * each item in the list is a `pair`. For example, a list of
 * student names and their scores.
 *
 * Syntax:
 * vector<pair<string, int>> student_scores;
 *
 * student_scores.push_back( {"Rohan", 95} );
 * student_scores.push_back( {"Priya", 88} );
 *
 * // Now, to get Rohan's score:
 * int rohanScore = student_scores[0].second; // 95
 */
#include <iostream>

int main()
{

    //  pair<int, pair<char, int>> p = {1,{'a',3}};

    //  cout << p.first << endl; //1
    //  cout << p.second.first << endl; //a
    //  cout << p.second.second << endl; // 3

    vector<pair<int, int>> vec = {{1, 2}, {2, 3}, {3, 4}};

    vec.push_back({4, 5});  // Sinche PB just insert the value, thats why we have to make a pair manually here
    vec.emplace_back(4, 5); // It create inplace objects so we don't have to define the pair ourselves

    for (auto p : vec)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}