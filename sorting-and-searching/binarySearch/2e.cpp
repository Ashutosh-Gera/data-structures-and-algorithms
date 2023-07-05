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


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << setprecision(20);
    double c;
    cin >> c;

    double l = 0;
    double r = 1e9;

    loop(i, 0, 100) {
        double mid = l + (r-l) / 2;

        if (((pow(mid, 2) + sqrt(mid)) - c < pow(10, -10)) && ((pow(mid, 2) + sqrt(mid)) - c > -pow(10, -10))) {
            cout << mid << endl;
            break;
        } else if ((pow(mid, 2) + sqrt(mid)) > c) {
            r = mid;
        } else {
            l = mid;
        }
        // cout << l << " " << r << endl;
    }
    // cout << setprecision(10) << r << endl;
    
    return 0;
}