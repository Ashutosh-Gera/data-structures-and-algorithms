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

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    loop(i, 0, n) {
        cin >> a[i];
    }
    loop(i, 0, m) {
        cin >> b[i];
    }

    ll count = 0;
    int i = 0;
    int j = 0;

    while (i < n && j < m) {
        if (i < n && a[i] < b[j]) i++;
        if (j < m && a[i] > b[j]) j++;
        
        if (i < n && j < m && a[i] == b[j]){
            ll countA = 0, countB = 0, val = a[i];
            while (i < n && a[i] == val){
                i++;
                countA++;
            }
            while (j < m && b[j] == val){
                j++;
                countB++;
            }
            count += (countA*countB);
        }
    }
    
    cout << count << endl;
    
    return 0;
}