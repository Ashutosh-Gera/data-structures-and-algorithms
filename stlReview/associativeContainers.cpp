#include <iostream>
using namespace std;

#include <set>
#include <map>
#include <algorithm>

//Associative containers : Set, Multiset, Map, Multimap
// typically implemented using binary tree
// ALWAYS SORTED

/*Associative container:
- Always sorted, default criteria is <
- No push_bacK(), push_front() [not needed]
*/

int main(void) {
    /*
    set
        - no duplicates
    */

   set<int> myset;
   myset.insert(3); //{3}
   myset.insert(1); // {1, 3}
   myset.insert(7); // {1, 3, 7} // Insertion takes O(logn) time!!!

   set<int>::iterator it;
   it = myset.find(7); // O(logn), it points to 7
   //Sequence containers don't usually have find member function

   //insert function actually returns a pair
   pair<set<int>::iterator, bool> ret;
   ret = myset.insert(3); // no new element inserted so ret.second would be false
   if (ret.second == false){
        it = ret.first; //"it" now points to element 3
   }

   myset.insert(it, 9); //"it" points to 3 but that doesn't mean 9 would be inserted at that place
                        // it just gives a "hint" about the actual position of 9 which helps
                        // to reduce the complexity of insertion from O(logn) => O(1)
                        // {1, 3, 7, 9}
    
    myset.erase(it); // {1, 7, 9}
    myset.erase(7); // {1, 9}

    //set.erase(iterator) is O(1) while set.erase(value) is O(log(set.size()))
    //(since, set.erase(value) == set.erase(set.find(value)))

    /*
    Multiset
        - A set that allows duplicate elements
    */

   // set/multiset: Value of the elements CANNOT be modified
   // -> *it = 10; // *it is read only

   /*Properties:
   1. Fast search: O(logn)
   2. Traversing is slow (compared to vector and deque)
   3. No random access, no [] operator.
   */

    // Map/multimap -> have same interface as set/multiset except that each value is a pair of key and value.

    /*
    Map:
        - no duplicate key
    */

    map<char, int> mymap;
    mymap.insert(pair<char,int>('a', 100));
    mymap.insert(make_pair('z', 200));

    map<char,int>::iterator itr = mymap.begin();
    mymap.insert(itr, {'b', 300}); // "it" is a hint

    itr = mymap.find('z'); //O(logn)

    //showing content:
    for (auto itr = mymap.begin(); itr != mymap.end(); itr++){
        cout << (*itr).first << " => " << (*itr).second << endl;
    }

    //multimap is a map that allows duplicate keys
    multimap<char, int> myMap;
    
    //map/multimap:
    // --keys cannot be modified 
    // type of *itr: pair<const char, int>
    // (*it).first = 9; will give error

    

}