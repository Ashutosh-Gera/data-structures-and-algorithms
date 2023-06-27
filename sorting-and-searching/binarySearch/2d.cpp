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

int loons(int t, int z, int y, int T) {
    if ((T / t) <= z) {
        return T / t;
    }
    
}

bool func() {

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(n);
    loop(i, 0, n) {
        int x, y, z;
        cin >> x >> y >> z;
        a.pb({x, y, z});
    }

    
    return 0;
}