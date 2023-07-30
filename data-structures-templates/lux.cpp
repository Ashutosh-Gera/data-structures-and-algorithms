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

int solve(vector<int>& r, vector<int>& c, int n, int curIdx, int left, int right) {
    if (curIdx > n) return 1e9;
    if (left <= 0 && right >= n) {
        return 0;
    }

    //include curIdx
    int ans1 = c[curIdx] + solve(r, c, n, curIdx + 1, min(left, curIdx - r[curIdx]), max(right, curIdx + r[curIdx]));

    //not include
    int ans2 = solve(r, c, n, curIdx + 1, left, right);

    return min(ans1, ans2);
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    //cin >> tc;
    loop(t, 0, tc) {
        int n;
        cin >> n;

        //length of the garden

        vector<int> r(n+1);
        loop(i, 0, n+1) cin >> r[i];
        vector<int> c(n+1);
        loop(i, 0, n+1) cin >> c[i];

        int ans = solve(r, c, n, 0, INT_MAX, INT_MIN);

        cout << (ans == 1e9 ? -1 : ans) << endl;

    }
    
    return 0;
}

