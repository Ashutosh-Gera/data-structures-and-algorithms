#include <iostream>
#include <vector>

using namespace std;

#define endl    '\n' 
#define loop(i, a, b) for (long long i = a; i < b; ++i) //[a, b)

struct x {
    long long t;
    long long z;
    long long y;
};

long long loons(x a, long long time) {
    long long result = 0;

    result += a.z * (time / (a.t * a.z + a.y));
    long long rem = time % (a.t * a.z + a.y);
    if (rem >= (a.t * a.z)) result += a.z;
    else result += rem / a.t;

    return result;
}

bool good(x* arr, long long m, long long n, long long t) {
    long long sum = 0;
    loop(i, 0, n) {
        sum += loons(arr[i], t);
    }
    return sum >= m;
}

void solve(x* arr, long long m, long long n) {
    long long l = -1; //l is bad
    long long r = 2e9 + 1;  //r is good

    //while (!good(arr, m, n, r)) r <<= 1;

    while (r > l+1) {
        long long mid = l + (r-l)/2;

        if (good(arr, m, n, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << endl;
    for (long long i = 0; i < n; i++) {
        if (i > 0) cout << " ";

        long long w = loons(arr[i], r);
        cout << min(m, w);
        m -= min(m, w);
    }
    cout << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long m, n;
    cin >> m >> n;
    // m = num balong longons
    // n = num assistants
    x* arr = new x[n];

    loop(i, 0, n) {
        x tmp;
        cin >> tmp.t >> tmp.z >> tmp.y;
        arr[i] = tmp;
    }

    solve(arr, m, n); 


    // loop(i, 0, n) {
    //     cout << arr[i].t << " " << arr[i].z << " " << arr[i].y << endl;
    // }
    
    
    return 0;
}



//Failed attempt below (TLE at tc5)

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;


// //syntax: typedef <currentName> <newName>
// typedef long long long long;
// typedef vector<long long> vlong long;
// typedef pair<long long, long long> plong long;

// const long long mod = 1000000007;
// const long long inf = long longONG_MAX;
// const long long neg_inf = long longONG_MIN;

// #define endl    '\n' 
// #define f       first
// #define s       second 
// #define pb      push_back    
// #define mp      make_pair
// #define sz(x)   (long long)x.size()

// #define loop(i, a, b) for (long long i = a; i < b; ++i) //[a, b)


// // better loon function
// // long long loons(long long t, long long z, long long y, long long T) {
// //     long long fulong long_cycles = T / (t * (z + y)); // Number of complete cycles
// //     long long remaining_time = T % (t * (z + y)); // Remaining time after complete cycles

// //     long long balong longoons = fulong long_cycles * z; // Total balong longoons from complete cycles

// //     if (remaining_time >= t * z) {
// //         balong longoons += z; // Inflate z balong longoons if enough time remains for a complete cycle
// //         remaining_time -= t * z;
// //     } else {
// //         balong longoons += remaining_time / t; // Inflate partial balong longoons with remaining time
// //         remaining_time = 0;
// //     }

// //     return balong longoons;
// // }

// long long loons(long long t, long long z, long long y, long long T) {
//     if ((T / t) <= z) {
//         return T / t;
//     }
//     long long total = 0;
//     long long shift = 0;
//     long long timePassed = 0;
//     while (timePassed < T) {
//         if (shift == z) {
//             shift = 0;
//             timePassed += y;
//         } else {
//             timePassed += t;
//             shift++;
//             total++;
//         }
//     }
//     return total;
// }

// bool func(vector<vector<long long>>& a, long long n, long long m, long long T) {
//     long long sum = 0;
//     loop(i, 0, n) {
//         sum += loons(a[i][0], a[i][1], a[i][2], T);
//     }
//     return sum == m;
// }

// void solve(vector<vector<long long>>& a, long long n, long long m) {
//     long long l = 0;
//     long long r = 1;
//     while (!func(a, n, m, r)){ r <<= 1;}

//     while (r > l + 1) {
//         long long mid = l + (r-l)/2;
//         if (func(a, n, m, mid)) {
//             r = mid;
//         } else {
//             l = mid;
//         }
//     } 
//     cout << r << endl;
//     loop(i, 0, n) {
//         cout << loons(a[i][0], a[i][1], a[i][2], r) << " ";
//     }
//     cout << endl;
// }

// int main(){

//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     long long m, n;
//     cin >> m >> n;

//     vector<vector<long long>> a(n);
//     loop(i, 0, n) {
//         long long x, y, z;
//         cin >> x >> y >> z;
//         a[i] = {x, y, z};
//     }
//     solve(a, n, m);
//     // cout << ans << endl;
//     // loop(i, 0, n) {
//     //     cout << loons(a[i][0], a[i][1], a[i][2], ans) << " ";
//     // }
//     // cout << endl;

//     return 0;
// }