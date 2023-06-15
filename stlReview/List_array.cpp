#include <iostream>
using namespace std;

#include <list>
#include <array>
#include <algorithm>

int main(void) {

    /*list
        -- doubly linked list
    */

    list<int> myList = { 5, 2, 9 };
    myList.push_back(8); // {5, 2, 9, 8}
    myList.push_front(4); // {4, 5, 2, 9, 8}

    list<int>::iterator itr = find(myList.begin(), myList.end(), 2); // itr -> 2
    myList.insert(itr, 6); // {4, 5, 6, 2, 9, 8}
                            // O(1) -> faster than vector/deque
    itr++; // itr -> 9
    myList.erase(itr); // {4, 5, 6, 2, 8} // O(1)

    /*Properties:
    1. Fast insert/remove at ANY place: O(1)
    2. slow search: O(n)
    3, No random access, no [] operator
    */

   // MOST USEFUL APPLICATION/FUNCTION OF LIST: SPLICE FUNCTION
   //e.g - myList.splice(itr, myList2, itr_a, itr_b); // O(1)   
    list<int> list1 = {10, 20};
    list<int> list2 = {30, 40, 50};

    list1.splice(list1.end(), list2, list2.begin(), list2.end());

    // list1 after splice operation: { 10, 20, 30, 40, 50 }
    // list1.size() = 5; list2.size() = 0                            

    /*Forward list
        -- singly linked list
    */
}