#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//syntax: typedef <currentName> <newName>
typedef long long ll;
typedef vector<int> vInt;
typedef pair<int, int> pInt;


//macros
#define endl "\n" 
#define F first
#define S second 
#define PB push_back    
#define MP make_pair

#define loop(i, a, b) for (int i = a; i <= b; i++) //for loop from a to b both inclusive

void hanoi(int n, int src, int dst, int tmp){
    if (n > 0){
        hanoi(n-1, src, tmp, dst);
        cout << "Moving disk " << n << " from " << src << " to " << dst << endl;
        hanoi(n-1, tmp, dst, src);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    hanoi(n, 0, 2, 1);
    /*
        disc 1 number 1 is smallest and disc numbered n in largest.
        pegs are numbered as: source = 0; destination = 2 and tmp = 1
    */
    
    return 0;
}