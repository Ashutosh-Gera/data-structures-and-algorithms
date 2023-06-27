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

bool func(int n, int x, int y, int t) {
    return floor(t/x) + floor(t/y) >= n;
}

int solve(int n, int x, int y) {
    int l = 0;
    int r = 1e9;

    while (r > l + 1) {
        int mid = l + (r-l)/2;

        if (func(n, x, y, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x, y;
    cin >> n >> x >> y;

    if (n == 1) {
        cout << min(x, y) << endl;
        return 0;
    }

    cout << min(x, y) + solve(n-1, x, y) << endl;
    
    return 0;
}