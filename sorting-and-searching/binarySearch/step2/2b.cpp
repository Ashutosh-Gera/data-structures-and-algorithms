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

bool func(vector<int> a, int n, int k, double x){
    int sum = 0;

    loop(i, 0, n) {
        sum += floor(a[i] / x);
    }

    return sum >= k;
}

double search(vector<int> a, int n, int k) {
    double l = 0; // l is good
    double r = 1e8; //r is bad

    //****** maintain the loop invariant ***** <- This observation is imp
    // that f(l) = 1 && f(r) = 0

    // since we are dealing with real numbers
    // we either need to do while loop like
    // while(r-l < epsilen) where epsilen is some
    // very small number (depending on the amt of precision we need)
    // or more simpler way, we can do below for loop (60-100 iterations is the maxm
    // we require for most of the problems so it works)
    loop(i, 0, 100) {
        double mid = l + (r-l)/2;
        if (func(a, n, k, mid)) {
            l = mid;
        } else {
            r = mid;
        }
        // cout << i << " " << l << " " << r << endl; <- this line helps visualize how many iterations
        // of the search we actually require.
    }
    return l;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10); 


    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    loop(i, 0, n) {
        cin >> a[i];
    }

    cout << search(a, n, k) << endl;
    return 0;
}