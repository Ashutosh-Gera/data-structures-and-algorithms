#include <iostream>
using namespace std;

typedef long long ll;


void printArray(int* arr, int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int* arr, int p, int q, int r){

    int n1 = q - p + 1;
    int n2 = r - q;

    int* L = new int[n1+1]; //one extra spot for sentinel cards in both arrays
    int* R = new int[n2+1];

    int i, j, k;

    for (int i = 0; i < n1; i++){
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[q + j + 1];
    }

    L[n1] = INT32_MAX;
    R[n2] = INT32_MAX;

    i = 0; j = 0;

    for (int k = p; k <= r; k++){
        if (L[i] <= R[j]){
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int *arr, int p, int r){
    if (p >= r) return;

    int q = (p + r)/2;

    mergeSort(arr, p, q);
    mergeSort(arr, q+1, r);
    merge(arr, p, q, r);

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
        mergeSort(arr, 0, n - 1);
        cout << "The sorted array is: ";
        printArray(arr, n);

    }

    return 0;

}