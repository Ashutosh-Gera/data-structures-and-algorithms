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

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    //cin >> tc;
    loop(t, 0, tc) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        unordered_map<int, int> count;
        loop(i, 0, n) {
            cin >> a[i];
        }

        ll ans = 0;
        ll numUnique = 0;
        int l = 0;
        loop(r, 0, n) {
            count[a[r]]++;
            if (count[a[r]] == 1) {
                numUnique++; //add(x)
            }
            while (numUnique > k) { //while !good
                count[a[l]]--;
                if (count[a[l]] == 0) {
                    numUnique--; //remove(x)
                }
                l++;
            }
            ans += r - l + 1;
        }
        cout << ans << endl;
    }
    
    return 0;
}

