#include <iostream>
using namespace std;

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

// Internally implemented using Hash tables
// If we have a good hash functions, finding an element in these containers
// takes the least amount of time (O(1)) among all containers!!!
// Hash table provides **Amortized** constant time searching

int main(void) {

    /*
    Unordered Set
    */
    unordered_set<string> mySet = { "red", "green", "blue" };
    unordered_set<string>::const_iterator itr = mySet.find("green"); // O(1) ***********
    if (itr != mySet.end()) { //Important check because if iterator doesn't find the element, it returns the end iterator
        cout << *itr << endl; // and dereferencing the end iterator results in undefined behaviour
    }
    mySet.insert("yellow"); // O(1)

    // can use it with other containers also
    vector<string> vec = { "purple", "pink" };
    mySet.insert(vec.begin(), vec.end()); //inserts every item in the vector into our unordered set

    //Hash table specific APIs:
    cout << "load_factor = " << mySet.load_factor() << endl;
    string x = "red";
    cout << x << " is in bucket #" << mySet.bucket(x) << endl;
    cout << "Total bucket #" << mySet.bucket_count() << endl;

    // unordered multiset: unordered set that allows duplicate elements
    // unordered map: unordered set of pairs
    // unordered multimap: unordered map that allows duplicated keys

    //hash collision => performance degrade

    /* 
    Properties of unordered containers:
        1. Fastest search/insert at any place: O(1)
            -Associative containers take O(logn)
            - vector/deque takes O(n)
            - list takes O(1) to insert, O(n) to search
        2. Unordered set/multiset: Element Value CanNOT be changed
            Unordered map/multimap: Element key canNOT be changed
    */

   /*
        Associative Array:
            - can be implemented using map and unordered map
    */

   unordered_map<char, string> day = { {'S', "Sunday"}, {'M', "Monday"} };

   cout << day['S'] << endl; //No range check
   cout << day.at('S') << endl; //has range check

   vector<int> vec = {1, 2, 3};
   vec[5] = 5; //compile error!!!

   day['W'] = "Wednesday"; //Inserting {'W', "Wednesday"} to day
   day.insert(make_pair('F', "Friday")); // Inserting {'F', "Friday"}

   day.insert(make_pair('M', "Monday")); //Fail to modify, it is an unordered map
   day['M'] = "Monday"; //succeed to modify
}

/*
Notes about Associative Arrays:
    - Search time: Unordered_map, O(1); map, O(logn)
    - unordered_map may degrade to O(n)
    - Can't use multimap or unordered multimap cuz they don't have unique keys and [] operator!!!
*/

void foo(const unordered_map<char, string>& m) {
    //m['S'] = "Sunday"; // won't work cuz m isn't modifiable
    // cout << m['S'] << endl; *** This also WON'T WORK because the subscript operator provides a WRITE
    // operation to the container, hence, this code won't compile!!!

    //correct way to print:
    auto itr = m.find('S');
    if (itr != m.end()) {
        cout << itr->second << endl;
    }
}

/*
    Container Adaptor:
        - Provide a restricted interface to meet special needs
        - Implemented with fundamental container classes

        1. Stack: LIFO, push(), pop(), top()

        2. Queue: FIFO, push(), pop(), front(), back()

        3. priority_queue: first item always has the greatest priority, push(), pop(), top()

*/

/* Another way of categorizing containers:
    - Array based containers: vector, deque

    - Node based containers: list, associative containers, unordered containers

    NOTE: Array based containers invalidates pointers:
        (i.e) - Native pointers, iterators, references

    But this doesn't happen in node based containers, their pointers do not get invalidated upon insertion
    or removal as long as the pointee is not deleted.
*/

vector<int> vect = {1, 2, 3, 4};
int* p = &vect[2]; //p points to 3
//vect.insert(vect.begin(), 0);
//cout << *p << endl; This will result in undefined behaviour since the pointer p got invalidated due to insertion