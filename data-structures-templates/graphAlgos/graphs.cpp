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


void dfs(vector<list<int>>& graph, int n, int m, int v, vector<bool>& visited, vector<int>& topSort) {
    if (!visited[v]){
        cout << v << " "; 
    }
    visited[v] = true;
    for (auto neighbour : graph[v]) {
        if (!visited[neighbour]) {
            dfs(graph, n, m, neighbour, visited, topSort);
        }
    }  
    topSort.push_back(v);  // topological sort for DAG
    // cout << endl; //har bottom element pe jaane ke baad ye endl print hoga
    // NOTE: If we have cycle in our graph, we can't make topological ordering!! 
}

// 5 7 3 5 3 1 3 4 4 1 5 1 5 2 1 2
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    // n -> vertices
    // m -> edges
    cin >> n >> m;

    vector<list<int>> adjList(n + 1);
    // Here, I am assuming graph vertices are numbered from 1,2,...,n
    loop(i, 0, m) {
        //input edges
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        // adjList[v].push_back(u); //for undirected only
    }

    // we now have our list ready, lets first do dfs
    vector<bool> visited(n+1, false);
    vector<int> topSort; //will store vertices in reverse topological order
    // int sourceVertex;
    // cin >> sourceVertex;
    cout << "DFS:" << endl;
    loop(i, 1, n+1) {
        if (!visited[i]) dfs(adjList, n, m, i, visited, topSort);
        // this condition handles disconnected graph as well as non strongly connected graph
        // if need to not do this loop, then make an additional graph node(0)
        // and connect 0 with all other nodes and then call dfs on 0
    }
    cout << endl;

    // for DAG only
    cout << "Topological order of nodes is" << endl;
    for (auto it = topSort.rbegin(); it != topSort.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    //Another way to topological sort the graph without using dfs
    //make a vector count[v] which contains the number of incoming edges to vertex v
    vector<int> count(n+1, 0);
    loop(i, 1, n+1) {
        for (auto& j : adjList[i]) {
            count[j]++;
        }
    }
    //make a set which contains the vertices with zero incoming edges
    queue<int> z; //set of zeroes
    loop(i, 1, n+1) {
        if (count[i] == 0){
            z.push(i);
        }
    }
    vector<int> topSort2;
    while (!z.empty()) {
        int curVertex = z.front();
        z.pop();
        topSort2.push_back(curVertex);
        for (auto& neighbour : adjList[curVertex]) {
            count[neighbour]--;
            if (count[neighbour] == 0) {
                z.push(neighbour);
            }
        }
    }

    if ((int) topSort2.size() == n) {
        cout << "(2) Topological order of nodes is" << endl;
        for (auto it = topSort2.begin(); it != topSort2.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    } else {
        cout << "Graph is cyclic" << endl;
    }


    // Now doing BFS
    // First create a level array which would contain the nodes at that level (levels will range from
    // 0 (source) till n-1 (if there are n nodes))
    vector<list<int>> level(n);
    //let's say we are doing bfs from vertex 1 (our graph has vertices 1, 2, 3, ... ,n)
    vector<int> d(n + 1, -1); //store the distances
    int source = 3; // can change source
    d[source] = 0;
    level[0].push_back(source);
    loop(k, 0, n - 1) {
        for (auto v : level[k]) {
            for (auto u : adjList[v]) {
                if (d[u] == -1) {
                    d[u] = k+1;
                    level[k+1].push_back(u);
                }
            }
        }
    }
    cout << "Shortest distance from node 1 to n is: " << d[2] << endl;


    
    return 0;
}

