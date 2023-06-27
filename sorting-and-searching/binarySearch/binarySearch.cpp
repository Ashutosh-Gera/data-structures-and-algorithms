#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//syntax: typedef <currentName> <newName>
typedef long long ll;
typedef vector<int> vInt;
typedef pair<int, int> pInt;

const ll mod = 1000000007;
const ll inf = LLONG_MAX;
const ll neg_inf = LLONG_MIN;

#define endl    '\n' 
#define f       first
#define s       second 
#define pb      push_back    
#define mp      make_pair
#define sz(x)   (int)x.size()

#define loop(i, a, b) for (int i = a; i < b; ++i) //[a, b)

//returns index of target number
//vec should be sorted
int binarySearch(vector<int>& vec, int target) {
    int l = 0;
    int r = (int)sz(vec) - 1;

    while (l <= r) {
        int mid = l + (r-l)/2; 
        // We calculate mid like above instead of simply doing (l+r)/2 because (l+r)/2 may cause an overflow
        // error so always do it like this to prevent overflow
        if (vec.at(mid) == target) {
            return mid;
        } else if (vec.at(mid) < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1; //return -1 if target not found
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> vec = { 3, 5, 7, 9, 11 };
    cout << binarySearch(vec, 5) << endl;

    return 0;
}