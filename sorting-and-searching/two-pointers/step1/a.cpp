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

    vector<int> c(n+m);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n || j < m) {
        if (j == m || (i < n && a[i] < b[j])) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    loop(i, 0, n+m) {
        cout << c[i] << " ";
    }
    cout << endl;
    
    return 0;
}