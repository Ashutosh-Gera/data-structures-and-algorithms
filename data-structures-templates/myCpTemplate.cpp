// This file contains my Cpp boiler template and useful guidelines..
// To compile the code
// g++ -std=c++17 -O2 -Wall test.cpp -o test
// -O2 => Optimizes the code
// -Wall => shows warnings about possible errors
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Below will contain all the typedefines i make
//syntax: typedef <currentName> <newName>
typedef long long ll;
typedef vector<int> vInt;
typedef pair<int, int> pInt;


//defining macros here
#define endl '\n' //This is because "\n" works faster than endl, because endl always causes a flush operation
#define f first
#define s second 
#define pb push_back    
#define mp make_pair

#define loop(i, a, b) for (int i = a; i <= b; i++) //for loop from a to b both inclusive


int main(){

    //Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);



}

//Normally we gonna use cin and cout for I/O mostly but below are some alternates
// If we need to read the WHOLE input line (possibily contaning spaces), then we use getline function
// Syntax:
// string s;
// getline(cin, s); // will store the whole line in s

//If the amount of data is unknown then we can use the following syntax:
// while (cin >> x){
    //code
//} => This loop reads elements from input one after another, until there is no more data available in the input.

//For simple file I/O
//syntax:
// freopen("input.txt", "r", stdin)
// freopen ("output.txt", "w", stdout)
// after this, the program reads the input from input.txt and outputs to output.txt

//Gen info
// int (32-bit) range => -2 x 10^9 to 2 x 10^9
// long long (64-bit) range => -9 x 10^18 to 9 x 10^18
// __int128_t range => -10^38 to 10^38

// (a+b) mod m = (a mod m + b mod m) mod m; same for - and x
// easy way to make sure there are no negative remainders => x = x%m; if (x < 0) x += m; (this is in case there are subtractions in code and remainder may become negative)

