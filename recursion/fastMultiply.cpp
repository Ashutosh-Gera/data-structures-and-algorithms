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
    Karatsuba's Fast Multiply algorithm:
    To multiply to n digit numbers in sub-quadratic time
*/
ll fastMultiply(ll x, ll y, int n){
    //x and y are the numbers to be multiplied and n is the number of digits they have
    if (n == 1){
        return x*y;
    } else {
        int m = ceil(n / 2);
        ll a = floor(x / pow(10, m));
        ll b = x % (int) pow(10, m);
        ll c = floor(y / pow(10, m));
        ll d = y % (int) pow(10, m);

        ll e = fastMultiply(a, c, m);
        ll f = fastMultiply(b, d, m);
        ll g = fastMultiply(a - b, c - d, m);
        return (e*pow(10, 2*m)) + (pow(10, m) * (e + f - g)) + f;
    }
}
//Multiplies the numbers in O(n^log3) time i.e O(n^1.58)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll x, y;
    cin >> x >> y;

    cout << "The product is: " << fastMultiply(x, y, n) << endl;
    return 0;
}