#include <iostream>
using namespace std;

/*
STL Headers
*/
#include <vector>
#include <deque>
#include <list>
#include <set> //includes set and multiset
#include <map> //includes map and multimap
#include <unordered_set> //unordered set/multiset
#include <unordered_map> //unordered map/multimap
#include <iterator>
#include <algorithm>
#include <numeric> //some numeric algorithm
#include <functional>


int main() {

    /*
            Vector -> Vector is dynamically allocated contiguous array in memory
    */
    class Dog;
    // Example 1:
    vector<Dog> vect(6);  // vec.capacity() == 6, vec.size() == 6, 
                        // 6 Dogs created with default constructor

    // Example 2:
    vector<Dog> vect; // vec.capacity() >= 0, vec.size() == 0
    vect.resize(6);   // vec.capacity() >= 6, vec.size() == 6, 
                    // 6 Dogs created with default constructor  

    // Example 3:
    vector<Dog> vect;
    vect.reserve(6);   // vec.capacity() >= 6, vec.size() == 0, 
                        // no default constructor invoked
    
    /*
    * Strategy of avoiding reallocation:
    * 1. If the maximum number of item is known, reserve(MAX);
    * 2. If unknown, reserve as much as you can, once all data a inserted, 
    *    trim off the rest.
    */


    vector<int> vec; //vec.size() == 0
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);  // vec: {4, 1, 8}

    cout << vec[2]; // 8 (no range check)
    cout << vec.at(2); // 8 (throws range_error exception out of range)

    vector<int>::iterator itr1 = vec.begin();  // half-open:  [begin, end)
    vector<int>::iterator itr2 = vec.end();

    sort(itr1, itr2);  // vec: {1, 4, 8}

    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    for (vector<int>::iterator /*auto*/ itr = vec.begin(); itr != vec.end(); itr++){
        cout << *itr << " "; // -> UNIVERSAL WAY TO TRAVERSE A CONTAINER
    }
    for (auto it : vec){
        cout << it << " ";
    }

    // Common member functions provided by all containers:-
    // vec = {4, 1, 8}
    if (vec.empty()) {/*do something*/}
    
    cout << vec.size(); // 3
    
    vector<int> vec2(vec); //Copy constructor, vec2 = {4, 1, 8}

    vec.clear(); //Remove all items in vec; vec.size() == 0

    vec2.swap(vec); //vec2 becomes empty and vec has 3 items now

    /* Properties of vector:
    *   1. fast insert/remove at the end: O(1)
    *   2. slow insert/remove at the beginning or in the middle: O(n)
    *   3. slow search : O(n)
    */

    /*
        Deque
    */
    deque<int> deq = { 4, 6, 7 };
    deq.push_front(2); // {2, 4, 6, 7}
    deq.push_back(8); // {2, 4, 6, 7, 8}

    //deq has similar interface with vector
    cout << deq[1]; // 4

    /* Properties:
    1. fast insert/remove at the beginning and the end.
    2. slow insert/remove in the middle : O(n)
    3. slow search : O(n)
    */


   /*
    * deque
    *
    * - No reallocation 
    *   deque has no reserve() and capacity()
    * - Slightly slower than vector
    */

    /*
    * Which one to use?
    *
    * - Need to push_front a lot?  -> deque
    *
    * - Performance is important?   -> vector
    */

    /*
    * 1. Element type
    *   - When the elements are not of a trivial type, deque is not much less 
    *   efficient than vector.
    */


    /*
    * 2. Memory Availability
    *   Could allocation of large contiguous memory be a problem? 
    *   - Limited memory size
    *   - Large trunk of data
    */


    /*
    * 3. Frequency of Unpredictable Growth
    */
    vector<int> vectt;
    for (int x=0; x<1025; x++) 
        vectt.push_back(x);   // 11 reallocations performed (growth ratio = 2)

                //   workaround: reserve()
    

    /*
    * 4. Invalidation of pointers/references/iterators because of growth
    */
    vector<int> vecttt = {2,3,4,5}; 
    int* p = &vecttt[3];
    vecttt.push_back(6);
    cout << *p << endl;  // Undefined behavior

    deque<int> deq = {2,3,4,5};
    p = &deq[3];
    deq.push_back(6);
    cout << *p << endl;  // OK
    // push_front() is OK too
    // deque: inserting at either end won't invalidate pointers

    // Note: removing or inserting in the middle still will invalidate 
    //       pointers/references/iterators


    /*
    * Summary:
    * 1. Frequent push_front()    - deque
    * 2. High performance         - vector
    * 3. Non-trivial data type    - deque
    * 4. Contiguous memory        - deque
    * 5. Unpredictable growth     - deque
    * 6. Pointer integrity        - deque
    * 7. Talk to C                - vector
    */

}
