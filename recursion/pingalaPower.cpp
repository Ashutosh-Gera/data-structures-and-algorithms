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

/*
    Algorithm to calculate a^n in O(logn) time
*/
ll pingalaPower(ll a, int n){
    if (n == 1) { 
        return a;
    } else {
        ll x = pingalaPower(a, n/2);
        if (n % 2 == 0){
            return x*x;
        } else {
            return x*x*a;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a;
    int n;
    cin >> a >> n;

    cout << "a^n is : " << pingalaPower(a, n) << endl;
    
    return 0;
}