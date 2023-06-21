#include <iostream>
#include <bits/stdc++.h>
#include <cstring>

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
#define MOD 998244353

#define loop(i, a, b) for (int i = a; i <= b; i++) //for loop from a to b both inclusive


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n; //the number of cards
    int maxColor = INT_MIN; //stores the maximum colour number we have!!
    pair<int,int>* arr = new pair<int, int>[n];
    loop(i, 0, n - 1){
        int a, b;
        cin >> a >> b;
        arr[i] = MP(a, b);
        maxColor = max({maxColor, a, b});
    }
    // loop(i, 0, n - 1){
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }
    //cout << maxColor << endl;
    //we will solve this using bottom up dp
    
    vector<pair<ll, ll>> dp;
    dp.PB(MP(1,1));
    loop(i, 1, n - 1){
        ll a = 0; ll b = 0;
        if (arr[i].first != arr[i-1].first){
            a += dp[i-1].first % MOD;
        }
        if (arr[i].first != arr[i-1].second){
            a += dp[i-1].second % MOD;
        }
        if (arr[i].second != arr[i-1].first){
            b += dp[i-1].first % MOD;
        }
        if (arr[i].second != arr[i-1].second){
            b += dp[i-1].second % MOD;
        }
        a = a % MOD;
        b = b % MOD;
        dp.PB(MP(a, b));
    }

    cout << (dp[n-1].first + dp[n-1].second) % MOD << endl;
    

    return 0;
}