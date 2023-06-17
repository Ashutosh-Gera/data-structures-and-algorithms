#include <iostream>
using namespace std;

#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <forward_list>

int myFunction(int i) {
    return i*i;
}

bool isOdd(int i) {
    return i%2;
}

int main(void) {

    /*  Iterators */
    // 1. Random access iterator: vector, deque, array
    vector<int>::iterator itr;
    vector<int>::iterator itr1;
    vector<int>::iterator itr2;
    itr = itr + 5; //advance itr by 5
    itr = itr - 4;
    //if (itr2 > itr1) { ...do something }
    ++itr; // faster than itr++
    --itr; //basically we can manipulate and use random access iterators however we want

    // 2. BiDirectional iterator: list, set/multiset, map/multimap
    list<int>::iterator itr;
    ++itr;
    --itr; //can only increment/decrement

    // 3. Forward iterator: forward list
    forward_list<int>::iterator itr;
    ++itr; //can only increment 

    // NOTE: Unordered containers provice "at least" forward iterators

    // 4. Input iterator: read and process values while iterating forward
    int x = *itr;

    // 5. Output Iterator: output values while iterating forward
    *itr = 100;

    //Every container has a iterator and a const_iterator
    set<int>::iterator itr;
    set<int>::const_iterator citr; //read_only access to container elements

    set<int> myset = { 2, 4, 5, 1, 9 };
    for (citr = myset.begin(); citr != myset.end(); ++citr) {
        cout << *citr << endl;
        // *citr = 3; (won't work)
    }

    //also have library function to directly use citrs with algorithm functions
    for_each(myset.cbegin(), myset.cend(), myFunction); //calls myFunction on each and every element of myset
    // though myFunction can only read elements of myset not modify them!!

    //Iterator Functions: (useful for non random access itrs)
    advance(itr, 5); // Move itr forward 5 spots i.e equivalent to itr += 5. ***A convenient function for non random access iterators***
    distance(itr1, itr2); //measure the distance b/w itr1 and itr2

    /* Iterator Adaptor
        - A special, more powerful iterator
        
        1. Insert iterator
        2. Stream iterator
        3. Reverse iterator
        4. Move iterator 

    */

   // 1. Insert Iterator:
   vector<int> vec1 = { 4, 5 };
   vector<int> vec2 = { 12, 14, 16, 18 };
   vector<int>::iterator it = find(vec2.begin(), vec2.end(), 16);
   insert_iterator<vector<int>> i_itr(vec2, it);
   copy(vec1.begin(), vec1.end() //source
        , i_itr);               //destination
    //vec2 = { 12, 14, 4, 5, 16, 18 }
    //Other insert iterators: back_insert_iterator, front_insert_iterator

    // 2. Stream Iterator:
    //  - to iterate through a data to & from a stream

    vector<string> vec4;
    //copy everything from stdin and back insert into vec4
    copy(istream_iterator<string>(cin), istream_iterator<string>(), // (iterate thorugh the data from stdin, end of string character,
        back_inserter(vec4));                                       // returns a back insert iterator to vec4)
    
    // print everything in vec4 to stdout with each element separated by " "
    copy(vec4.begin(), vec4.end(), ostream_iterator<string>(cout, " "));

    // Make it terse:
    copy(istream_iterator<string>(cin), istream_iterator<string>(), ostream_iterator<string>(cout, " "));
    //see how using STL, 1 line of code can achieve complicated things :)

    // 3. Reverse Iterator:
    vector<int> vec = { 4, 5, 6, 7 };
    reverse_iterator<vector<int>::iterator> ritr;
    for (ritr = vec.rbegin(); ritr != vec.rend(); ++ritr) {
        cout << *ritr << endl; // prints 7 6 5 4
    }

    /* Algorithms
        - mostly loops 
    Thus, if you see a for/while loop in your code, consider replacing them using a function of algorithm lib
    to make the code more efficient, less buggy, more readable
    */

    vector<int> vec = { 4, 2, 5, 1, 3, 9 };
    vector<int>::iterator itr = min_element(vec.begin(), vec.end()); //itr -> 1

    // Note 1. Algorithm always process ranges in a half-open way: [begin, end)

    sort(vec.begin(), itr); // vec : { 2, 4, 5, 1, 3, 9 }
    reverse(itr, vec.end()); // vec : { 2, 4, 5, 9, 3, 1 } itr => 9

    // Note 2:
    vector<int> vec2(3);
    copy(itr, vec.end(), //source
        vec2.begin());  //destination
        //vec2 needs to have atleast space for 3 elements otherwise undefined behaviour 
        //this is efficient but not safe ^
    
    // Note 3:
    vector<int> vec3;
    copy(itr, vec.end(), back_inserter(vec3)); //Inserting instead of overwriting
                        //back insert iterator // Safe but NOT efficient

    vec3.insert(vec3.end(), itr, vec.end()); //Efficient AND safe :D

    // Note 4: Algorithm with function!!
    vector<int> vec = { 2, 4, 5, 9, 2 };
    vector<int>::iterator itr = find_if(vec.begin(), vec.end(), isOdd);
                                // itr -> 5
    
    // Note 5: Algorithm with native C++ array
    int arr[4] = { 6, 3, 7, 4 };
    sort(arr, arr+4); //will sort the array

        
    
    return 0;
}