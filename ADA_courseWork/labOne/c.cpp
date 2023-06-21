#include <iostream>
using namespace std;

typedef long long ll;

template <typename T,typename U>                                                   
pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}

pair<int, string> numBitFlips(string A, string &B){

    if (A.length() == 0 || B.length() == 0) return {0, B};

    if (A == B) return {0, B};

    int n1 = A.length();
    int n2 = B.length(); // n1 = n2 all the time tho!
    int numFlips = 0;

    if ((n1 % 2 == 1) && (n2 % 2 == 1)){
        string str;
        for (int i = 0; i < n1; i++){
            if (A[i] != B[i]){
                str.push_back(A[i]);
                numFlips++;
            } else {
                str.push_back(B[i]);
            }
        }
        return {numFlips, str};
    }


    string A1 = A.substr(0, n1/2);
    string A2 = A.substr(n1/2, n1 - A1.length());

    string B1 = B.substr(0, n2/2);
    string B2 = B.substr(n2/2, n2 - B1.length());

    pair<int, string> smallAns1 = numBitFlips(A1, B1) + numBitFlips(A2, B2);
    pair <int, string> smallAns2 = numBitFlips(A2, B1) + numBitFlips(A1, B2);

    return smallAns1.first > smallAns2.first ? smallAns2 : smallAns1;
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

        string A,B;
        cin >> A >> B;

        //You have access to string B, and want to make changes to it such that B becomes a sloppy shuffle of A.
        // To do so, you can perform several (possibly zero) bit flips on B. That is, for any bit Bi in B, you can change Bi from 0 to 1 or from 1 to 0.
        //need to print Minimum number of bit slips required by B
        // print the final correct string B
        //cout << A << " " << B << endl;
        //cout << A[0] << endl << B[0];
        pair<int, string> output = numBitFlips(A, B);
        cout << output.first << "\n" << output.second << "\n";
    }

    return 0;

}