#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//syntax: typedef <currentName> <newName>
typedef long long ll;
typedef vector<int> vInt;
typedef pair<int, int> pInt;


//macros
#define endl "\n" 
#define F first
#define S second 
#define PB push_back    
#define MP make_pair

#define loop(i, a, b) for (int i = a; i <= b; i++) //for loop from a to b both inclusive

/*
    QUICKSELECT or ONE-ARMED QUICKSORT:
    Selecting the k-th smallest element in a n element array.
    Algorithm: partition the array (same partition algorithm as quicksort) and then 
    recursively search only the sub array which contains the kth smallest element of 
    the input array
*/

//Our algorithm takes O(nlogn) time generally, with its worst case time complexity being O(n^2)
int partition(int* arr, int p, int r, int pivotIndex){
    swap(arr[pivotIndex], arr[r]);
    int cse = p - 1;
    loop(i, p, r - 1){
        if (arr[i] < arr[r]){
            cse++;
            swap(arr[cse], arr[i]);
        }
    }
    swap(arr[r], arr[cse+1]);
    return cse + 1;
}

int quickSelect(int* arr, int p, int r, int k){
    if (k <= 0) {
        cout << "Invalid value of k (<= 0), returning -1 signifying error." << endl;
        return -1;
    }
    if (p == r) {
        return arr[p];
    } else {
        int pivotIndexBefore = (p + (p+r)/2 + r)/3; //pivot
        int pivotIndexAfter = partition(arr, p, r, pivotIndexBefore);

        if (k < pivotIndexAfter){
            return quickSelect(arr, p, pivotIndexAfter - 1, k);
        } else if (k > pivotIndexAfter) {
            return quickSelect(arr, pivotIndexAfter + 1, r, k);
        } else {
            return arr[pivotIndexAfter];
        }
    }
}
//Side Note: the algorithm time complexity depends on how we choose our pivots.
// To find median in Linear time: We can use Blum-Floyd-Pratt-rivest-tarjan 's algorithm of MEDIAN OF MEDIANS(MOM) to select the pivot
// and in that casee our algorithm works in Linear time (~16n, exactly).
// Though, in practice, the right way to choose the pivot element is to choose it uniformly at random,
// in that case the running time to find the median is atmost 4n. (Read more about randomized algorithms)


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int* arr = new int(n);
    loop(i, 0, n - 1){
        cin >> arr[i];
    }

    cout << "The " << k << "-th smallest element is: " << quickSelect(arr, 0, n - 1, k - 1) << endl; //k - 1 cuz indexing starts from 0

    
    return 0;
}