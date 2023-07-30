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
#define pb      push_back    
#define mp      make_pair
#define sz(x)   (int)x.size()
#define prDouble(x) cout << fixed << setprecision(10) << x

#define loop(i, a, b) for (int i = a; i < b; ++i) //for loop [a, b)

int n, m;

void recursiveDfs(vector<list<int>>& graph, int curVertex, vector<bool>& visited) {
    if (!visited[curVertex]) {
        cout << curVertex << " ";
        visited[curVertex] = true;
        for (auto neighbour : graph[curVertex]) {
            recursiveDfs(graph, neighbour,  visited);
        }
    }
}

void iterativeDfs(vector<list<int>>& graph, int curVertex, vector<bool>& visited) {
    stack<int> s;
    s.push(curVertex);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            cout << current << " ";
            visited[current] = true;
            for (auto neighbour : graph[current]) {
                s.push(neighbour);
            }
        }
    }
}

void Dfs(vector<list<int>>& graph) {
    vector<bool> visited(n + 1, false);

    int components = 0;
    loop(source, 1, n + 1) {
        if (!visited[source]) {
            components++;
            // recursiveDfs(graph, source, visited);
            iterativeDfs(graph, source, visited);
        }
    }
    cout << endl << "Number of components: " << components << endl;
}


//Undirected connected graph:
// 11 11 1 2 1 6 1 7 2 3 2 4 2 5 6 5 7 9 7 11 4 8 9 10

//Undirected disconnected graph:
// 8 6 1 2 2 3 1 4 4 5 4 6 7 8
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // n -> vertices
    // m -> edges
    cin >> n >> m;

    vector<list<int>> graph(n + 1);
    //assuming graph has vertices numbered from 1,2,3,...,n
    loop(i, 0, m) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
        //undirected unweighted graph
    }

    Dfs(graph);
    

    
    
    return 0;
}

