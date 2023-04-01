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

//Program to print all the possible permutations of a given array!!

vInt permutation;
bool chosen[100] = {false};

void search(int arr[], int n){
    if ((int) permutation.size() == n){
        //process permutation; i'll print it
        for (auto i : permutation){
            cout << i << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < n; i++){
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.PB(arr[i]);
            search(arr, n);
            chosen[i] = false;
            permutation.pop_back();       
        }
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

    search(arr, n);

    
    return 0;
}