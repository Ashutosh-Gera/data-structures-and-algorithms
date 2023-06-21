#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void printPairArray(pair<int, int> arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i].first << " " << arr[i].second << '\n';
    }
    cout << '\n';
}

int solve(pair<int, int> arr[], int n){
    int numOfIntersections = 0;

    for (int i = 0; i < n; i++){
        
        int j = n - 1;
        while (i < j){
            if (arr[i].second > arr[j].second){
                numOfIntersections++;
            }
            j--;
            if (arr[j].first == arr[i].first){
                break;
            }
        }
    }
    return numOfIntersections;
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n; //number of wires

    pair<int, int> arr[n]; // an array containing all the pairs of wires

    for (int i = 0; i < n; i++){
        
        int x, y;
        cin >> x >> y;
        pair <int, int> elem(x, y);
        arr[i] = elem;
    }

    //printPairArray(arr, n);
    sort(arr, arr + n);
    //printPairArray(arr, n);
    cout << solve(arr, n) << '\n';

    return 0;

}