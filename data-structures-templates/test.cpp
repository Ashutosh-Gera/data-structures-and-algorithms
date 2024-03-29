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

ll solve(vector<vector<int>>& vec, int row, int col, int n, int m, ll prevSum) {
    if (row == n - 1 && col == m - 1) {
        return prevSum;
    }

    if (row >= n || col >= m) {
        return NEG_INF; // Return a very large negative value for invalid paths
    }

    // Move down or right
    ll ans1 = 0;
    ll ans2 = 0;
    ll ans3 = 0;
    // ll ans4 = solve(vec, row + 1, col, n, m, prevSum);
    // ll ans5 = solve(vec, row, col + 1, n, m, prevSum);

    if (row < n - 1) {
        ans1 = solve(vec, row + 1, col, n, m, prevSum + vec[row+1][col] - vec[row][col]);
    }
    if (col < m - 1) {
        ans2 = solve(vec, row, col + 1, n, m, prevSum + vec[row][col+1] - vec[row][col]);
    }

    // Move diagonally
    if (row < n - 1 && col < m - 1) {
        ans3 = solve(vec, row + 1, col + 1, n, m, prevSum + vec[row+1][col+1] - vec[row][col]);
    }

    // Return the maximum of the three options
    return max({ans1, ans2, ans3});
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    //cin >> tc;
    loop(t, 0, tc) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));

        loop(i, 0, n) {
            loop(j, 0, m) {
                cin >> a[i][j];
            }
        }
        ll ans = 0;
        loop(i, 0, n) {
            loop(j, 0, m) {
                ans = max(ans, solve(a, i, j, n, m, 0));
            }
        }
        // ans = max(ans, solve(a, 0, 0, n, m, 0));
        cout << ans << endl;
        // loop(i, 0, n) {
        //     loop(j, 0, m) {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }


    }
    
    return 0;
}