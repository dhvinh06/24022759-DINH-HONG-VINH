#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1001;

vector<int> adj[MAX];
bool visited[MAX];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(int u) {
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}//de quy

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

