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

//more universal approach
bool bSearch2(int* arr, int n, int target) {
    int l = -1;
    int r = n;
    int mid;
    while (r > l + 1) {
        mid = l + (r-l)/2;
        if (arr[mid] < target) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (r < n && arr[r] == target) return true;
    return false;
}

bool binarySearch(int* arr, int n, int target) {
    int l = 0;
    int r = n - 1;

    while (l <= r) {
        int mid = l + (r-l)/2;
        if (arr[mid] == target) return true;
        else if (arr[mid] > target) r = mid - 1;
        else l = mid + 1;
    }
    return false;
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
        int tmp;
        cin >> tmp;
        if (bSearch2(arr, n, tmp)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}