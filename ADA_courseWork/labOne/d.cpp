#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool areSloppy(string A, string B) {

    if (A.length() == 0 || B.length() == 0){
        return false;
    }
    if (A == B) return true;

    if (A.length() == 1 || B.length() == 1){
        return false;
    }

    int n1 = A.length();
    int n2 = B.length();

    string A1 = A.substr(0, n1/2);
    string A2 = A.substr(n1/2, n1 - A1.length());

    string B1 = B.substr(0, n2/2);
    string B2 = B.substr(n2/2, n2 - B1.length());

    if ((A1.length() != A2.length()) || (B2.length() != B1.length())){
        return false;
    }

    return (areSloppy(A1, B1) && areSloppy(A2, B2)) || (areSloppy(A1, B2) && areSloppy(A2, B1));
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int testcase = 1; testcase <= t; testcase++){

        int n;
        cin >> n;
        // n = length of strings A and B
        string A;
        cin >> A;
        string B;
        cin >> B;

        if (areSloppy(A,B)){
           cout << "YES" << "\n";
        } else {
           cout << "NO" << "\n";
        }


    }

    return 0;

}