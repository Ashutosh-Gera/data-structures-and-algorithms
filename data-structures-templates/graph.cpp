#include <iostream>
#include <queue>

using namespace std;

void printDfs(bool** adjMatrix, int V, int sv, bool* visited);
void printBfs(bool** adjMatrix, int V, int sv, bool* visited);

void DFS(bool** adjMatrix, int V) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            printDfs(adjMatrix, V, i, visited);
        }
    }

    delete [] visited;
}

void BFS(bool** adjMatrix, int V) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            printBfs(adjMatrix, V, i, visited);
        }
    } 
    delete [] visited;
}


int main() {
    int V, E;
    cin >> V >> E;

    //2d array for storing edges i.e adjacency matrix
    bool** adjMatrix = new bool*[V];

    for (int i = 0; i < V; ++i) {
        adjMatrix[i] = new bool[V];
        for (int j = 0; j < V; ++j) {
            adjMatrix[i][j] = false; //initialising
        }
    }

    //taking input edges
    for (int i = 0; i < E; ++i) {
        int f, s;
        cin >> f >> s;
        adjMatrix[f][s] = true;
        adjMatrix[s][f] = true;
    }

    
    cout << "DFS" << endl;
    DFS(adjMatrix, V);
    cout << "BFS" << endl;
    BFS(adjMatrix, V);


    //delete the memory
    for (int i = 0; i < V; ++i) {
        delete [] adjMatrix[i];
    }
    delete [] adjMatrix;
}

//DFS for connected graph
void printDfs(bool** adjMatrix, int V, int sv, bool* visited) { //sv -> starting vertex
    cout << sv << '\n';
    visited[sv] = true;
    for (int i = 0; i < V; ++i) {
        if (i == sv) continue;
        if (adjMatrix[sv][i] == true && !visited[i]) {
            printDfs(adjMatrix, V, i, visited);
        }
    }
}

//BFS for connected graph
void printBfs(bool** adjMatrix, int V, int sv, bool* visited) { 
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    visited[sv] = true;
    while (!pendingNodes.empty()) {
        int curVertex = pendingNodes.front();
        pendingNodes.pop();

        for (int i = 0; i < V; i++) {
            if (i == curVertex) continue;
            if (adjMatrix[curVertex][i] == true && !visited[i]) {
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
        cout << curVertex << endl;
    }
}
