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

int solve(int* arr, int n, int target) {
    int l = 0;
    int r = n - 1;
    int idx = n;
    int mid;
    while (l <= r) {
        mid = l + (r-l)/2;
        if (arr[mid] >= target) {
            idx = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return idx+1;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int* arr = new int[n];
    loop(i, 0, n) {
        cin >> arr[i];
    }
    loop(i, 0, k) {
        int query;
        cin >> query;
        cout << solve(arr, n, query) << endl;
    }
    
    return 0;
}