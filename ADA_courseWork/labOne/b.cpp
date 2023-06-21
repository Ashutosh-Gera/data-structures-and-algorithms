#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void printPairArray(pair<ll, ll> arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i].first << " " << arr[i].second << '\n';
    }
    //cout << '\n';
}

ll merge(pair<ll, ll> arr[], int p, int q, int r){

    ll invCount = 0;
    int n1 = q - p + 1;
    int n2 = r - q;

    ll* L = new ll[n1+1];
    ll* R = new ll[n2+1];

    //one extra spot for sentinel cards in both arrays

    int i, j, k;

    for (int i = 0; i < n1; i++){
        L[i] = arr[p + i].second;
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[q + j + 1].second;
    }

    L[n1] = INT64_MAX;
    R[n2] = INT64_MAX;

    i = 0; j = 0;

    for (int k = p; k <= r; k++){
        if (L[i] <= R[j]){
            arr[k].second = L[i++];
        } else {
            arr[k].second = R[j++];
            invCount += (n1 - i);
        }
    }
    delete[] L;
    delete[] R;
    return invCount;
}

ll mergeSort(pair<ll,ll> arr[], int p, int r){
    if (p >= r) return 0;

    int q = (p + r)/2;

    return mergeSort(arr, p, q) + mergeSort(arr, q+1, r) + merge(arr, p, q, r);

}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n; //number of wires

    pair<ll, ll> arr[n]; // an array containing all the pairs of wires

    for (int i = 0; i < n; i++){
        
        ll x, y;
        cin >> x >> y;
        pair <ll, ll> elem(x, y);
        arr[i] = elem;
    }

    //printPairArray(arr, n);
    sort(arr, arr + n);
    cout << mergeSort(arr, 0, n-1) << "\n";

    return 0;

}