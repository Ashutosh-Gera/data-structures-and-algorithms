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

/*Returns true if s1 is subsequence of s2*/
bool good(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    /*If i reaches end of s1,that mean we found all
    characters of s1 in s2,
    so s1 is subsequence of s2, else not*/
    return i == n;
}

//returns true iff s is a subsequence of t
// below good function was working properly but TLE aa rha tha!!!
// bool good(string s, string t) {
//     if (s == t) return true;

//     if (s.empty()) return true;

//     if (t.empty() && !s.empty()) return false;

//     if (s[0] == t[0]) {
//         return good(s.substr(1, sz(s)- 1), t.substr(1, sz(t) - 1));
//     }

//     return good(s, t.substr(1, sz(t)-1));
    
// }

int solve(const string t, const string p, vector<int>& a) {
    int l = -1; //l is good
    int r = sz(a); //sz(a) == sz(t) // r is bad

    while (r > l + 1) {
        int mid = l + (r-l)/2;
        string m;
        vector<int> b(a);
        sort(b.begin() + mid, b.end());
        loop(i, mid, sz(a)){
            m += t[b[i]];
        } 
        if (good(p, m)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string t;
    string p;

    cin >> t >> p;

    vector<int> a(sz(t));
    loop(i, 0, sz(t)) {
        cin >> a[i];
        --a[i];
    }

    cout << solve(t, p, a) << endl;

    // loop(i, 0, sz(a)){
    //     cout << a[i] << " ";
    // }
    // cout << good(p, t) << endl;

    


    return 0;
}