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

bool func(int a, int b, int n, ll x) {
    return (x/a)*(x/b) >= n;
}

ll search(int a, int b, int n) {
    ll l = 0; // cannot have square less than zero size.
    // we will chose 2 pointers l and r such that the below
    // invariants hold at all times
    // func(l) = 0 && func(r) = 1

    // ll r = max(a, b) * n; We could have done this, but this may cause an overflow error
    ll r = 1; // so we will find r  in terms of power of 2
    while (!func(a, b, n, r)) {
        r *= 2;
    }
    
    while (r > l + 1) {
        ll mid = l + (r-l)/2;
        if (func(a, b, n, mid)) {
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

    int a, b, n;
    cin >> a >> b >> n;

    cout << search(a, b, n) << endl;
    
    return 0;
}