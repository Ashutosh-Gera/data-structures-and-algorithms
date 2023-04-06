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

void printArray(int *arr, int n){
    loop(i, 0, n-1){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//using Nico Lumoto parition
int partition(int* arr, int p, int r, int pivotIndex){
    swap(arr[pivotIndex], arr[r]); //putting the pivot on last
    int cse = p - 1 ;//#items < pivot //index of smaller element
    loop(i, p, r - 1){
        if (arr[i] < arr[r]){
            cse++;
            swap(arr[cse], arr[i]);
        }
    }
    swap(arr[r], arr[cse+1]);
    return cse+1;
}

void quicksort(int* arr, int p, int r){
    if (r > p) {
        //chosing a pivot element
        int pivotIndex = (p + ((p+r)/2) + r) / 3;
        int q = partition(arr, p, r, pivotIndex);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int* arr = new int(n);
    loop(i, 0, n - 1){
        cin >> arr[i]; 
    }

    printArray(arr, n);
    quicksort(arr, 0, n - 1);
    printArray(arr, n);
    
    return 0;
}