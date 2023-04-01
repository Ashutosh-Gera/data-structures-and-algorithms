#include <iostream>
using namespace std;

typedef long long ll;

void insertionSort(int *arr, int n){

    int i, j;
    for (j = 1; j < n; j++){

        int key = arr[j];
        //insert arr[j] into the sorted sequence
        i = j - 1;
        while (i >= 0 && arr[i] > key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}

void printArray(int* arr, int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(void) {

    int t;
    cin >> t;

    for (int testcase = 1; testcase <= t; testcase++){

        int n;
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++){
            int elem;
            cin >> elem;
            arr[i] = elem;
        }
        cout << "The entered array is: ";
        printArray(arr, n);
        insertionSort(arr, n);
        cout << "The sorted array is: ";
        printArray(arr, n);
    }

    return 0;

}