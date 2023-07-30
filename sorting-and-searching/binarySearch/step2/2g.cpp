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

bool good(const vector<int>& a, int n, int k, int x) {
    ll sum = 0;
    loop(i, 0, n) {
        sum += a[i];
    }
    //sum has total num of students across all groups

    if (sum < (x*k)) return false;

    int i = 0;
    int j = k - 1;

    while (j < n) {
        
    }
}  

int solve(const vector<int>& a, int n, int k) {

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    int n;
    cin >> n;
    vector<int> a(n);
    loop(i, 0, n) {
        cin >> a[i];
    }

    
    return 0;
}