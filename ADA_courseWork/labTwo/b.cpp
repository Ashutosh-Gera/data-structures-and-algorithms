#include <iostream>
#include <bits/stdc++.h>
#include <cstring>

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
#define MOD 1000000007

#define loop(i, a, b) for (int i = a; i <= b; i++) //for loop from a to b both inclusive

//global vars
int n;
vector<int> adj[100001];
long long dp[100001][2];

void dfs(int root) {
    stack<pair<int, int>> s;
    s.push({ root, -1 });
    while (!s.empty()) {
        int node = s.top().first, parent = s.top().second;
        if (dp[node][0] == 0 && dp[node][1] == 0) {
            dp[node][0] = 1;
            dp[node][1] = 1;
            for (int child : adj[node]) {
                if (child != parent) {
                    s.push({ child, node });
                }
            }
        } else {
            for (int child : adj[node]) {
                if (child != parent) {
                    dp[node][0] = (dp[node][0] * dp[child][1]) % MOD;
                    dp[node][1] = (dp[node][1] * (dp[child][0] + dp[child][1])) % MOD;
                }
            }
            s.pop();
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // create adjacency list to store the tree
    cin >> n;
    loop(i, 1, n){
        adj[i].clear();
    }

    //initialize all values to zero
    memset(dp, 0, sizeof(dp));
    
    // input 
    loop(i, 1, n - 1){
        int u, v;
        cin >> u >> v;

        // add edge to adjacency list
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // The tree is stored as an adjacency list
    // We can access the nodes adjacent to node u by iterating over adj[u].
    // loop(i, 0, (int) adj[1].size() - 1){
    //     cout << adj[1][i] << endl;
    // }

    dfs(1);
    cout << (dp[1][0] + dp[1][1]) % MOD << endl;

    return 0;
}