/*
          _____                    _____                    _____                    _____          
         /\    \                  /\    \                  /\    \                  /\    \         
        /::\    \                /::\    \                /::\____\                /::\____\        
       /::::\    \              /::::\    \              /:::/    /               /:::/    /        
      /::::::\    \            /::::::\    \            /:::/    /               /:::/    /         
     /:::/\:::\    \          /:::/\:::\    \          /:::/    /               /:::/    /          
    /:::/__\:::\    \        /:::/__\:::\    \        /:::/____/               /:::/    /           
   /::::\   \:::\    \       \:::\   \:::\    \      /::::\    \              /:::/    /            
  /::::::\   \:::\    \    ___\:::\   \:::\    \    /::::::\    \   _____    /:::/    /      _____  
 /:::/\:::\   \:::\    \  /\   \:::\   \:::\    \  /:::/\:::\    \ /\    \  /:::/____/      /\    \ 
/:::/  \:::\   \:::\____\/::\   \:::\   \:::\____\/:::/  \:::\    /::\____\|:::|    /      /::\____\
\::/    \:::\  /:::/    /\:::\   \:::\   \::/    /\::/    \:::\  /:::/    /|:::|____\     /:::/    /
 \/____/ \:::\/:::/    /  \:::\   \:::\   \/____/  \/____/ \:::\/:::/    /  \:::\    \   /:::/    / 
          \::::::/    /    \:::\   \:::\    \               \::::::/    /    \:::\    \ /:::/    /  
           \::::/    /      \:::\   \:::\____\               \::::/    /      \:::\    /:::/    /   
           /:::/    /        \:::\  /:::/    /               /:::/    /        \:::\__/:::/    /    
          /:::/    /          \:::\/:::/    /               /:::/    /          \::::::::/    /     
         /:::/    /            \::::::/    /               /:::/    /            \::::::/    /      
        /:::/    /              \::::/    /               /:::/    /              \::::/    /       
        \::/    /                \::/    /                \::/    /                \::/____/        
         \/____/                  \/____/                  \/____/                  ~~              
                                                                                                    
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//syntax: typedef <currentName> <newName>
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const ll MOD = 1000000007;
const ll INF = INT64_MAX;
const ll NEG_INF = INT64_MIN;

//defining macros here
#define endl    '\n' 
#define f       first
#define s       second 
#define pb      push_back    
#define mp      make_pair
#define sz(x)   (int)x.size()
#define prDouble(x) cout << fixed << setprecision(10) << x

#define loop(i, a, b) for (int i = a; i < b; ++i) //for loop [a, b)

struct stack {

    vector<ll> s, smin = {INF}, smax = {NEG_INF};

    void push(ll x) {
        s.push_back(x);
        smin.push_back(::min(smin.back(), x));
        smax.push_back(::max(smax.back(), x));
    }

    ll pop() {
        ll res = s.back();
        s.pop_back();
        smin.pop_back();
        smax.pop_back();

        return res;
    }

    bool empty() {
        return s.empty();
    }

    ll min() {
        return smin.back();
    }

    ll max() {
        return smax.back();
    }
};

::stack s1, s2;

void add(ll x) {
    s2.push(x);
}

void remove(ll x) {
    if (s1.empty()) {
        while (!s2.empty()) {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

ll k;

bool good() {
    ll mx = max(s1.max(), s2.max());
    ll mn = min(s1.min(), s2.min());
    return (mx - mn) <= k;
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    //cin >> tc;
    loop(t, 0, tc) {
        ll n;
        cin >> n >> k;
        vector<ll> a(n);
        loop(i, 0, n) {
            cin >> a[i];
        }
        ll res = 0;
        int l = 0;
        loop(r, 0, n) {
            add(a[r]);
            while (!good()) {
                remove(a[l]);
                l++;
            }
            res += r - l + 1;
        }
        cout << res << endl;
    }
    
    return 0;
}

