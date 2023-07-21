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

/* Generating Subsets
    You are given a set of numbers : {0 , 1 , 2 , 3 , 4}
    You have to find all the subsets of this set.
*/
vInt subset;

void search(int arr[], int n, int k){
    if (k == n){
        //process subset; i am printing the subset
        for (auto i : subset){
            cout << i << " ";
        }
        cout << endl;
    } else {
        //include k in the subset
        subset.PB(arr[k]);
        search(arr, n, k+1);
        subset.pop_back();

        //don't include k in the subset
        search(arr, n, k+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int *arr = new int(n);

    loop(i, 0, n - 1){
        cin >> arr[i];
    }
    search(arr, n, 0);
    return 0;
}